from scanner import Scanner
from scanner import Token
from sys import exit

class Node(object):
    def __init__(self, data,value=None):
        self.value =value
        self.data=data
        self.left = None
        self.right = None
        self.child=None
    def __str__(self):
        return self.value


class Parser(object):
    @staticmethod
    def make_tree(token_type, arg1=None, arg2=None):
        if token_type == 'CONST_ID':
            t = Node(token_type, arg1)
        elif token_type == 'T':
            t = Node('T')
        elif token_type == 'FUNC':
            # arg1代表函数名，arg2代表函数的参数表达式
            t = Node('FUNC', arg1)
            t.child = arg2
        else:
            t = Node(token_type)
            t.left = arg1
            t.right = arg2
        return t

    @staticmethod
    def print_tree(root, indent):
        for x in range(indent):
            print(' ', end='')
        if root.data == 'PLUS':
            print('+')
        elif root.data == 'MINUS':
            print('-')
        elif root.data == 'MUL':
            print('*')
        elif root.data == 'DIV':
            print('/')
        elif root.data == 'POWER':
            print('^')
        elif root.data == 'FUNC':
            print(root.value)
        elif root.data == 'CONST_ID':
            print(root.value)
        elif root.data == 'T':
            print('T')
        else:
            exit('错误的树节点')
        if root.data == 'CONST_ID' or root.data == 'T':
            return
        if root.data == 'FUNC':
            Parser.print_tree(root.child, indent + 2)
        else:
            Parser.print_tree(root.left, indent + 2)
            Parser.print_tree(root.right, indent + 2)
    def __init__(self,scanner):
        self.it=scanner.get_Token()#词法的迭代器
        self.token=Token()
        self.x=None
        self.y=None
        self.x_scale=None
        self.y_scale=None
        self.rot=None#旋转角度
        self.start=None#T的起始
        self.end=None#T的终点
        self.step=None#步长
        self.x_origin=None
        self.y_origin=None
    def FetchToken(self):
        self.token=next(self.it)
    def MatchToken(self,token_type):
        print('matchtoken',self.token.data)
        if self.token.Token_type!=token_type:
            print('不匹配的语法:',self.token.data)
            exit()
        self.FetchToken()
    def program(self):
        print('enter program')
        while True:
            try:
                self.statement()
                self.MatchToken('SEMICO')
            except StopIteration:
                print('所有输入正确！！！')
                break
            if self.token=='error_token':
                print('未能识别的单词')
                break
        print('exit program')
    def statement(self):
        print('enter statement')
        if self.token.Token_type=='ORIGIN':
            self.origin_statement()
        elif self.token.Token_type=='SCALE':
            self.scale_statement()
        elif self.token.Token_type=='ROT':
            self.rot_statement()
        elif self.token.Token_type=='FOR':
            self.for_statement()
        else:
            exit('error statement')
        print('exit statement')
    def origin_statement(self):
        print('enter origin_statement')
        self.MatchToken('ORIGIN')
        self.MatchToken('IS')
        self.MatchToken('L_BRACKET')
        self.x_origin=self.expression()
        self.MatchToken('COMMA')
        self.y_origin=self.expression()
        self.MatchToken('R_BRACKET')
        print('exit origin_statement')
    def scale_statement(self):
        print('enter scale_statement')
        self.MatchToken('SCALE')
        self.MatchToken('IS')
        self.MatchToken('L_BRACKET')
        self.x_scale=self.expression()
        self.MatchToken('COMMA')
        self.y_scale=self.expression()
        self.MatchToken('R_BRACKET')
        print('exit scale_statement')
    def rot_statement(self):
        print('enter rot_statement')
        self.MatchToken('ROT')
        self.MatchToken('IS')
        self.rot=self.expression()
        print('exit rot_statement')
    def for_statement(self):
        print('enter for_statement')
        self.MatchToken('FOR')
        self.MatchToken('T')
        self.MatchToken('FROM')
        self.start=self.expression()
        self.MatchToken('TO')
        self.end=self.expression()
        self.MatchToken('STEP')
        self.step=self.expression()
        self.MatchToken('DRAW')
        self.MatchToken('L_BRACKET')
        self.x=self.expression()
        self.MatchToken('COMMA')
        self.y=self.expression()#x,y保存的还得是表达式树才行啊,fuck!
        self.MatchToken('R_BRACKET')
        print('exit for_statement')
    def expression(self):
        print('enter expression')
        left=self.term()
        while self.token.Token_type=='PLUS' or self.token.Token_type=='MINUS':
            token_tmp=self.token.Token_type
            self.MatchToken(token_tmp)
            right=self.term()
            left=Parser.make_tree(token_tmp,left,right)
        Parser.print_tree(left,2)
        print('exit expression')
        return left
    def term(self):
        print('enter term')
        left=self.factor()
        while self.token.Token_type=='MUL' or self.token.Token_type=='DIV':
            token_tmp = self.token.Token_type
            self.MatchToken(token_tmp)
            right=self.factor()
            left=Parser.make_tree(token_tmp,left,right)
        print('exit term')
        return left
    def factor(self):
        print('enter factor')
        if self.token.Token_type=='PLUS':
            self.MatchToken('PLUS')
            right=self.factor()
        elif self.token.Token_type=='MINUS':
            self.MatchToken('MINUS')
            right=self.factor()
            left=Node('CONST_ID')
            left.value=0.0
            right=Parser.make_tree('MINUS',left,right)
        else:
            right=self.component()
        print('exit factor')
        return right
    def component(self):
        print('enter component')
        left=self.atom()
        if self.token.Token_type=='POWER':
            self.MatchToken('POWER')
            right=self.component()
            left=Parser.make_tree('POWER',left,right)
        print('exit component')
        return left
    def atom(self):
        tmp=self.token
        if self.token.Token_type=='CONST_ID':
            self.MatchToken('CONST_ID')
            t=Parser.make_tree('CONST_ID',tmp.value)
        elif self.token.Token_type=='T':
            self.MatchToken('T')
            t=Parser.make_tree('T')
        elif self.token.Token_type=='FUNC':
            func_name=self.token.data
            self.MatchToken('FUNC')
            self.MatchToken('L_BRACKET')
            s=self.expression()
            t=Parser.make_tree('FUNC',func_name,s)
            self.MatchToken('R_BRACKET')
        elif self.token.Token_type=='L_BRACKET':
            self.MatchToken('L_BRACKET')
            t=self.expression()
            self.MatchToken('R_BRACKET')
        else:
            exit('atom 错误')
        return t
    def __str__(self):
        return '[start:%s end:%s step:%s rot:%s x_origin:%s y_origin:%s]'%(self.start,self.end,self.step,self.rot,self.x_origin,self.y_origin)



if __name__ == '__main__':
    import cProfile
    import pstats
    profiler=cProfile.Profile()
    profiler.enable()

    myscanner = Scanner('haha.txt')
    myparser=Parser(myscanner)
    myparser.FetchToken()
    myparser.program()

    profiler.create_stats()
    stats=pstats.Stats(profiler)
    stats.strip_dirs().sort_stats('cumulative').print_stats()
    stats.print_callers()






