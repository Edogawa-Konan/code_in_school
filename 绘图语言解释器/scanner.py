class Token:
    def __init__(self,Token_type="",data="",value=0):
        self.Token_type=Token_type
        self.data=data  #输入的符号
        self.value=value #符号的值
    def __str__(self):
        return '[Token_type:%s  data:%s  value:%d]' % (self.Token_type,self.data,self.value)
'''
token_type=('ORIGIN','SCALE','ROT','IS','TO','STEP','DRAW','FOR','FROM',
            'T'
            'SEMICO','L_BRACKET','R_BRACKET','COMMA',
            'PLUS','MINUS','MUL','DIV','POWER',
            'FUNC',
            'CONST_ID',
            'NONTOKEN',
            'ERRTOKEN')
'''
token1=[Token('CONST_ID','PI',3.1415926),Token('CONST_ID','E',2.71828),Token('T','T',0.0),Token('FUNC','SIN',0.0),
       Token('FUNC','COS',0.0),Token('FUNC','TAN',0.0),Token('FUNC','LN',0.0),Token('FUNC','EXP',0.0),
       Token('FUNC','SQRT',0.0),Token('ORIGIN','ORIGIN',0.0),Token('SCALE','SCALE',0.0),Token('ROT','ROT',0.0),
       Token('IS','IS',0.0),Token('FOR','FOR',0.0),Token('FROM','FROM',0.0),Token('TO','TO',0.0),Token('STEP','STEP',0.0),
       Token('DRAW','DRAW',0.0)]

token=['PI','E','T','SIN','COS','TAN','LN','EXP','SQRT','ORIGIN','SCALE','ROT','IS','FOR','FROM','TO','STEP','DRAW']


class Scanner(object):
    def __init__(self,filename):
        f=open(filename,'r')
        self.lines=f.read().upper()+'@'
        f.close()
    def show_input(self):
        return self.lines
    def get_Token(self):
        L = iter(self.lines)
        char = L.__next__()
        temp = []  # 缓冲区
        while char is not '@':
            while char==' ' or char=='\n' or char=='\t'or char =='\r':
                char = L.__next__()
                if char=='@':#最后一行末尾有\n的
                    raise StopIteration
            if char.isalpha():
                while True:
                    if char.isalnum():
                        temp.append(char)
                        char = L.__next__()
                    else:
                        break
                item = ''.join(temp)
                if item in token:
                    for x in token1:
                        if x.data == item:
                            yield x
                temp = []
            elif char.isdigit():
                while True:
                    if char.isdigit():
                        temp.append(char)
                        char = L.__next__()
                    else:
                        break
                if char is '.':
                    temp.append(char)
                    char = L.__next__()
                    while True:
                        if char.isdigit():
                            temp.append(char)
                            char = L.__next__()
                        else:
                            break
                item = ''.join(temp)
                x = Token('CONST_ID', item, float(item))
                yield x
                temp = []
            elif char == ';':
                x = Token('SEMICO', char)
                yield x
                char = L.__next__()
            elif char == '(':
                x = Token('L_BRACKET', char)
                yield x
                char = L.__next__()
            elif char == ')':
                x = Token('R_BRACKET', char)
                yield x
                char = L.__next__()
            elif char == '+':
                x = Token('PLUS', char)
                yield x
                char = L.__next__()
            elif char == '-':
                x = Token('MINUS', char)
                yield x
                char = L.__next__()
            elif char == ',':
                x = Token('COMMA', char)
                yield x
                char = L.__next__()
            elif char is '/':
                char = L.__next__()
                if char == '/':
                    while char != '\n' and char != '@':
                        char = L.__next__()
                else:
                    x = Token('DIV', data='/')
                    yield x
            elif char == '*':
                x = Token('MUL', char)
                char=L.__next__()
                yield x
            elif char=='^':
                x = Token('POWER', char)
                char = L.__next__()
                yield x
            else:
                yield 'error_token'


if __name__=='__main__':
    s=Scanner('haha.txt')
    print(repr(s.show_input()))
    for x in s.get_Token():
       print(x)
