# -*- coding:utf-8 -*-
# -*- by prime -*-

import socket

class FTP:
    def __init__(self,address):
        self.sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        self.sock.connect((address,21))
        self.file=self.sock.makefile('r',encoding='utf-8')
        self.maxline=8192
        print(self.getwelcome())
    def login(self,name,password):
        return self.sendcmd('USER %s'%name)+'\r\n'+self.sendcmd('PASS %s'%password)

    def List(self):
        return self.PASV('LIST')
    def Quit(self):
        return self.PASV('QUIT')

    def getsingelline(self): #从服务器读取一行，去除\r\n
        line=self.file.readline(8192+1)
        if line[-2:]=='\r\n':
            line=line[:-2]
        if line[-1:] in ('\r','\n'):
            line=line[:-1]
        return line

    def sendcmd(self,cmd): #发送命令,返回得到的响应信息
        cmd+='\r\n'
        self.sock.sendall(cmd.encode())
        return self.getresponse()

    def getwelcome(self): #获取服务器的欢迎信息
        return self.getresponse()
    
    def getmultiline(self): #从服务器读取多行，用\n分割
        line=self.getsingelline()
        if line[3:4]=='-':
            code=line[:3]
            while True:
                nextline=self.getsingelline()
                line+='\n'+nextline
                if nextline[:3]==code and nextline[3:4]!='-':
                    break
        return line

    def getresponse(self): #返回从服务器获取的响应,这个只是针对于21端口即命令通道
        return self.getmultiline()

    def parsePASV(self,response): #从服务器响应中取出pasv的ip和端口号
        if response[:3]!='227':#服务器没有做好准备
            raise RuntimeError('服务器尚未进入被动模式，无法切换')
        import re
        pattern=re.compile(r'(\d+),(\d+),(\d+),(\d+),(\d+),(\d+)',re.ASCII)
        tmp=pattern.search(response) #match是只从头部匹配，因而这里用search
        numbers=tmp.groups()
        host='.'.join(numbers[:4])
        port=(int(numbers[4])<<8)+int(numbers[5])
        return host,port

    def PASV(self,cmd): #返回被动模式传输的数据,这是数据通道
        address,port=self.parsePASV(self.sendcmd('PASV'))
        print('现在进入PASV模式,欲连接的地址{}端口{}'.format(address,port))
        self.sendcmd('TYPE A') #以ascll模式进行数据传输
        with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as so,so.makefile('r',encoding='utf-8') as f:
            so.connect((address,port))
            print('现在已连接{}'.format(so.getpeername()))
            msg = self.sendcmd(cmd)
            print(msg)
            if cmd=='QUIT':
                return ([],msg)
            data_res=[]
            while True:
                line=f.readline(self.maxline+1)
                if not line:
                    break
                if line[-2:] == '\r\n':
                    line = line[:-2]
                elif line[-1:] == '\n':
                    line = line[:-1]
                print(line)
                data_res.append(line)
        return (data_res,self.getresponse()) #返回数据通道和命令通道的响应值




if __name__ == '__main__':
    client=FTP('192.168.229.1')
    client.login('prime','123')
    print(client.Quit())

