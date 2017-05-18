# -*- coding:utf-8 -*-
# -*- by prime -*-


import socket
from email.parser import Parser
from email.header import decode_header
from email.utils import parseaddr,parsedate



CR=b'\r'
LF=b'\n'
CRLF=CR+LF

_maxline=2048

class POP:
    def __init__(self,hostname,port=110):
        self.host=hostname
        self.port=port
        self.sock=socket.create_connection((self.host,self.port))
        self.file=self.sock.makefile('rb')
        self.welcome=self._getlines()[0]

    def _getresp(self):
        pass

    def _getlines(self): #从服务器读取一行信息，全局最耗时的担当
        '''
        :return: 返回（信息，长度），信息是只保留LF
        '''
        line=self.file.readline(_maxline+1)  # ..LF
        octets=len(line) #有几个字节?
        if line[:-2]==CRLF: # ...CRLF
            return line[:-2],octets
        if line[:1]==CR: #CR..LF
            return line[1:-1],octets
        return line[:-1],octets # ...LF

    def _getmultilines(self):  #返回['response', ['mesg_num octets', ...], octets].
        resp=self._getlines()[0]
        List=[]; octets=0
        line,num=self._getlines()
        while line !=b'.\r':
            if line.startswith(b'..'):
                num = num - 1
                line = line[1:]
            octets+=num
            List.append(line)
            # print(line)
            line, num = self._getlines()
        # t=b'\r\n'.join(List).decode('gbk')
        return (resp, List, octets)

    def _sendcmd(self,cmd): #把命令cmd发送到服务器,然后返回响应
        cmd=bytes(cmd,encoding='utf-8')
        self.sock.sendall(cmd+CRLF)
        return self._getlines()[0].decode()

    def _sendlongcmd(self,cmd):
        cmd = bytes(cmd, encoding='utf-8')
        self.sock.sendall(cmd + CRLF)
        return self._getmultilines()

    def STAT(self): #返回邮箱的状态 (信件总数,信件大小)
        source=self._sendcmd('STAT')
        tmp=source.split()
        return (int(tmp[1],int(tmp[2])))

    def USER(self,user):
        return self._sendcmd('USER {}'.format(user))

    def PASS(self,password):
        return self._sendcmd('PASS {}'.format(password))

    def LIST(self): #列出信件列表
        return self._sendlongcmd('LIST')

    def RETR(self,index): #下载信件
        return self._sendlongcmd('RETR {}'.format(index))

    def QUIT(self):  #关闭并退出
        res=self._sendcmd('QUIT')
        self.sock.close()
        return res


def decode_to_str(s):
    data,charset=decode_header(s)[0]  #返回[(字符串，编码符号)]
    if charset:
        data.decode(charset)
    return data

def print_mail(msg):
    for header in ('From','To','Date','Subject'):
        value=msg.get(header,'')
        if value:
            if header=='Subject':
                value=decode_to_str(value)
            elif header=='Date':
                value=parsedate(value)[:6] #解析时间字段，返回9-tuple
            else :
                realname,mailaddr=parseaddr(value) #解析地址，必须是包含地址的域，比如To或Cc，返回元组（真实姓名，邮箱地址）
                value="{}".format(mailaddr)
            print(header + ' : ',value)

    if (msg.is_multipart()):
        #Return True if the message’s payload is a list of sub-Message objects, otherwise return False.

        parts = msg.get_payload() #此时parts是一个message的列表
        '''
        Return the current payload, which will be a list of Message objects when is_multipart() is True,
         or a string when is_multipart() is False.
        默认参数i=None, decode=False，第一个表示列表索引；第二个表示是否解码，当然只能对非multipart有效
        '''
        for n, part in enumerate(parts):
            print('part %s' % n)
            print_mail(part) #递归打印文本信息
    else:
        content_type = msg.get_content_type()  #Return the message’s content type.类型强制为小写的mime类型
        if content_type == 'text/plain' or content_type == 'text/html':  #这些都是mime类型
            content = msg.get_payload(decode=True)
            charset = guess_charset(msg)
            # print('*'*50)
            # print(msg)
            if charset:
                content = content.decode(charset)
            print('Text: %s' % content)
        else:
            print('Attachment: %s' % content_type)


def guess_charset(msg):
    charset = msg.get_charset() #Return the Charset instance associated with the message’s payload.
    if charset is None:
        content_type = msg.get('Content-Type', '').lower()
        pos = content_type.find('charset=') #找到下标
        if pos >= 0:
            charset = content_type[pos + 8:].strip() #取出编码。
        '''
         strip([chars])：
        #Return a copy of the string with the leading and trailing characters removed.
        # The chars argument is a string specifying the set of characters to be removed
        #Characters are removed from the leading end until reaching a string character that is not
        # contained in the set of characters in chars. A similar action takes place on the trailing end.
        默认去除空格
        '''
    return charset



if __name__ == '__main__':
    p=POP('pop.163.com')
    print(p.welcome)
    print(p.USER('13173370316@163.com'))
    print(p.PASS('my951210'))
    print(b'\n'.join(p.LIST()[1]).decode('gb18030'))
    tmp=p.RETR('11')
    text=Parser().parsestr(b''.join(tmp[1]).decode())
    print_mail(text)
    print(p.QUIT())















