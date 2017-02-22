from myparser import Parser
from myparser import Scanner
import math
import random
import matplotlib.pyplot as pl

colors = ['r','g','y','m','b']

class Semantics(Parser):
    @staticmethod
    def get_expr_value(root, T=0.0):
        if root.data == 'PLUS':
            return Semantics.get_expr_value(root.left, T) + Semantics.get_expr_value(root.right, T)
        elif root.data == 'MINUS':
            return Semantics.get_expr_value(root.left, T) - Semantics.get_expr_value(root.right, T)
        elif root.data == 'MUL':
            return Semantics.get_expr_value(root.left, T) * Semantics.get_expr_value(root.right, T)
        elif root.data == 'DIV':
            return Semantics.get_expr_value(root.left, T) / Semantics.get_expr_value(root.right, T)
        elif root.data == 'POWER':
            return Semantics.get_expr_value(root.left, T) ** Semantics.get_expr_value(root.right, T)
        elif root.data == 'FUNC':
            if root.value == 'SIN':
                return math.sin(Semantics.get_expr_value(root.child, T))
            elif root.value == 'COS':
                return math.cos(Semantics.get_expr_value(root.child, T))
            else:
                print('错误的函数!!!fuck fuck fuck aaaaaaa', root.value, end='')
                exit()
        elif root.data == 'CONST_ID':
            return root.value
        elif root.data == 'T':
            return T
        else:
            return 0.0

    def origin_statement(self):
        print('enter origin_statement')
        self.MatchToken('ORIGIN')
        self.MatchToken('IS')
        self.MatchToken('L_BRACKET')
        tmp = self.expression()
        self.x_origin = Semantics.get_expr_value(tmp)
        print('x_origin==', self.x_origin)
        self.MatchToken('COMMA')
        tmp= self.expression()
        self.y_origin = Semantics.get_expr_value(tmp)
        print('y_origin==', self.y_origin)
        self.MatchToken('R_BRACKET')
        print('exit origin_statement')
    def scale_statement(self):
        print('enter scale_statement')
        self.MatchToken('SCALE')
        self.MatchToken('IS')
        self.MatchToken('L_BRACKET')
        tmp=self.expression()
        self.x_scale=Semantics.get_expr_value(tmp)
        print('x_scale==',self.x_scale)
        self.MatchToken('COMMA')
        tmp=self.expression()
        self.y_scale=Semantics.get_expr_value(tmp)
        print('y_scale==',self.y_scale)
        self.MatchToken('R_BRACKET')
        print('exit scale_statement')
    def rot_statement(self):
        print('enter rot_statement')
        self.MatchToken('ROT')
        self.MatchToken('IS')
        tmp=self.expression()
        self.rot=Semantics.get_expr_value(tmp)
        print('rot==',self.rot)
        print('exit rot_statement')
    def for_statement(self):
        print('enter for_statement')
        self.MatchToken('FOR')
        self.MatchToken('T')
        self.MatchToken('FROM')
        tmp=self.expression()
        self.start=Semantics.get_expr_value(tmp)
        print('start==',self.start)
        self.MatchToken('TO')
        tmp=self.expression()
        self.end=Semantics.get_expr_value(tmp)
        print('end==',self.end)
        self.MatchToken('STEP')
        tmp=self.expression()
        self.step=Semantics.get_expr_value(tmp)
        print('step==',self.step)
        self.MatchToken('DRAW')
        self.MatchToken('L_BRACKET')
        self.x=self.expression()
        self.MatchToken('COMMA')
        self.y=self.expression()#x,y保存的还得是表达式树才行啊,fuck!
        self.MatchToken('R_BRACKET')
        print('exit for_statement')
        self.draw()
    def draw(self):
        print(self)
        T = self.start
        while T <= self.end:
            # print('T=----------------------------------------------------',T)
            x = Semantics.get_expr_value(self.x, T)
            y = Semantics.get_expr_value(self.y, T)
            # x=math.sin(T)
            # y=math.cos(T)
            x_tmp = x * math.cos(self.rot) + y * math.sin(self.rot)
            y = y * math.cos(self.rot) - x * math.sin(self.rot)
            x = x_tmp
            x *= self.x_scale
            y *= self.y_scale
            x += self.x_origin
            y += self.y_origin
            print('x=--------------------------',x,'y=--------------------------',y)
            pl.scatter(x, y, color=colors[random.randint(0, 4)], marker='o', s=6)
            T += self.step
    def show(self):
        pl.figure(figsize=(10, 10))
        pl.title('14130110069--mayuan')
        self.FetchToken()
        self.program()
        pl.show()


if __name__ == '__main__':

    import cProfile
    import pstats
    profiler=cProfile.Profile()
    profiler.enable()


    #初始化词法和语法分析器
    myscanner = Scanner('haha.txt')
    mysemantics=Semantics(myscanner)

    #加了语义分析的语法分析器show time
    mysemantics.show()

    profiler.create_stats()
    stats=pstats.Stats(profiler)
    stats.strip_dirs().sort_stats('cumulative').print_stats()


