# -*- coding:utf-8 -*-
# -*- by prime -*-

#用tcp的connect做端口扫描
import socket
from concurrent.futures import ProcessPoolExecutor




def scan(address):
    with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
        # s.settimeout(1) #设置超时时间，不设置就是阻塞模式，否则就是非阻塞模式，超时未响应会引发socket.timeout异常
        if s.connect_ex((address[0],address[1]))==0: #和connect一样，不过连接失败不会引发异常而是返回一个指示器，为0表示连接成功
            print('port {} open'.format(address[1]))
            return 'port {} open'.format(address[1])
        # else:
        #     print('port {} close'.format(address[1]))


def tcp_scan(host):
    p=ProcessPoolExecutor(max_workers=8)
    p.map(scan,[(host,port) for port in [53,80,8080,3128,8081,9080,1080,21,23,443,69,22,25,110,7001,9090,3389,1521,1158,2100,1433]],chunksize=100) #把任务分块提交



if __name__ == '__main__':
    tcp_scan('127.0.0.1')










