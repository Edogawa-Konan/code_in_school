# -*- coding:utf-8 -*-
# -*- by prime -*-

import socket
import struct


class udp_scan:
    def __init__(self,hostname,timeout=3):
        self.host=hostname
        self.sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        self.sock.settimeout(timeout)
    def scan(self):
        for port in [53]:
            try:
                self.sock.sendto(b"",(socket.gethostbyname(self.host),port))
                self.sock.recvfrom(256)
            except socket.timeout:
                print('端口{}没有回复udp报文'.format(port))
                self.icmp_receive(port)
                continue
    def icmp_receive(self,port):
        icmp=socket.socket(socket.AF_INET,socket.SOCK_RAW,socket.IPPROTO_ICMP)
        icmp.settimeout(5)
        try:
            recPacket, addr = icmp.recvfrom(256)
        except:
            print('端口{}没有回复ICMP报文'.format(port))
            return
        icmpHeader = recPacket[20:28]  #IP数据包头部20个字节
        head_type, code, checksum, packetID, sequence = struct.unpack("bbHHh", icmpHeader)
        print('ICMP报文类型:{},返回代码:{}'.format(head_type,code))
        icmp.close()




if __name__ == '__main__':
    t=udp_scan('www.baidu.com')
    t.scan()
