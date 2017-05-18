# -*- coding:utf-8 -*-
# -*- by prime -*-

import struct
import socket
import time
import os
import select

ICMP_ECHO_REQUEST=8  #ping的icmp报文类型编码


class Ping:
    def __init__(self,host_name,timeout=2,times=4):
        '''
        :param host_name: 主机名
        :param timeout: 单次最大超时时间
        :param times: 发送几次响应
        '''
        self.host=host_name
        self.sock=socket.socket(socket.AF_INET,socket.SOCK_RAW,socket.getprotobyname('icmp')) #创建icmp的原始套接字
        self.timeout=timeout
        self.times=times
    def check_sum(self,source):
        '''
        :param source: 待计算的字符串
        :return: 校验和
        以16bit（2个字节）为一组，并将所有组相加（二进制求和）
        若高16bit不为0，则将高16bit与低16bit反复相加，直到高16bit的值为0，从而获得一个只有16bit长度的值
        将此16bit值进行按位求反操作，将所得值替换到校验和字段
        '''
        length=len(source)//2*2 #求长度的偶数值，即有多少个32位组
        res=0
        count=0
        while count<length:
            val=source[count+1]*256+source[count]
            res+=val
            res&=0xffffffff #二进制加法，高位丢弃，只留32位
            count+=2

        if count<len(source): #长度为奇数，有单独的一个字符
            res+=ord(source[-1])
            res&=0xffffffff
        #把32bit转换成16bit的校验和
        res=(res>>16)+(res&0xffff) #将高16位和低16位相加
        res+=(res>>16)  #将上述过程的进位再次加到低位
        res=~res
        res=res & 0xffff
        res=res>>8|(res<<8&0xFF00)
        return res

    def send_ping(self,ID): #伪造数据包
        my_checksum=0
        #b:signed char, h:short 2, H:unsigned short 2 小写有符号，大写无符号
        header=struct.pack('bbHHh',ICMP_ECHO_REQUEST,0,my_checksum,ID,1) #对应icmp报文头部的8个字节 1 1 2 2 2
        bytes_in_float=struct.calcsize('d')    #8位
        data = (192 - bytes_in_float) * b"A"   #正文瞎填充
        data=struct.pack('d',time.time())+data #正文加入8bit,表示发送时的时间,time.time()返回浮点数，表示累计秒数
        my_checksum=self.check_sum(header+data)
        header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, socket.htons(my_checksum), ID, 1)
        packet=header+data #要发送的包包
        self.sock.sendto(packet,(self.host,1))
        print('已经发送给{},发送的数据包的校验和:{}'.format(self.host,my_checksum))

    def get_receive(self,ID): #返回得到响应的用时，或者None表示超时未收到连接
        what_ready = select.select([self.sock], [], [], self.timeout)  # 超时时间单位s
        '''
        select.select(rlist, wlist, xlist[, timeout])
        wait until ready for read / write / exceptional condition
        The return value is a triple of lists of objects that are ready: subsets of the first three arguments.
         When the time-out is reached without a file descriptor becoming ready, three empty lists are returned.
        '''
        if what_ready[0] == []:#表明timeout了，程序返回即可
            return None
        rec_packet, addr = self.sock.recvfrom(1024)# The return value is a pair (message, address)
        icmp_header = rec_packet[20: 28] #8bit的报文头部
        ip_type, code, checksum, packet_ID, sequence = struct.unpack("bbHHh", icmp_header)
        print('ICMP响应报文头部信息————ICMP类型:{},代码:{},校验和:{},id:{},序号:{}'.format(ip_type,code,checksum,packet_ID,sequence))

        if packet_ID == ID and ip_type==0:
            bytes_In_double = struct.calcsize("d")
            time_sent = struct.unpack("d", rec_packet[28:28 + bytes_In_double])[0]  #把发送时候添加的时间取出来
            return time.time()-time_sent


    def ping(self):
        ID=os.getpid()&0xFFFF #把进程id当做报文id
        for x in range(self.times):
            self.send_ping(ID)
            delay=self.get_receive(ID)
            if delay:
                print('用时{}秒收到响应'.format(delay))
            else:
                print('{}秒内未收到回复，站点可能关闭'.format(self.timeout))



if __name__ == '__main__':
    t=Ping('www.github.com')
    t.ping()










