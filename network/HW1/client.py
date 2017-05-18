# -*- coding:utf-8 -*-
# -*- by prime -*-
import socket


def client(url):
    sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    sock.connect((url,80))
    # print(sock.getsockname())
    request_text=b'GET / HTTP/1.1\r\nHost:'+url.encode('utf-8')+b'\r\nConnection: close\r\n\r\n'
    sock.sendall(request_text)
    # sock.send(b'GET / HTTP/1.1\r\nHost: www.baidu.com\r\nConnection: close\r\n\r\n')
    data=[]
    while True:
        more=sock.recv(4096)
        if not more:
            break
        data.append(more)
    sock.close()
    reply=b''.join(data)#最终结果字符串
    reply =reply.decode('utf-8')
    headers,body=reply.split('\r\n\r\n',1)
    return headers,body





if __name__ == '__main__':
    res=client('www.sina.com.cn')
    # res=client('www.baidu.com')
    print(res[0])
    print(res[1])
