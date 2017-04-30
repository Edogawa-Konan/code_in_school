# -*- coding:utf-8 -*-
# -*- by prime -*-


def schedule(a):
    a=sorted(a)#非原地排序
    L=[sum(a[:i]) for i in range(1,len(a)+1)]
    return sum(L)/len(a)





