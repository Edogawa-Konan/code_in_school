# -*- coding:utf-8 -*-
# -*- by prime -*-

from functools import wraps

def Maxtrix_Chain(p):
    length=len(p)-1
    m=[[float('inf')]*(length) for i in range(length)]
    return _Lookup_chain(m,p,0,length-1)

def _Lookup_chain(m,p,i,j):
    if m[i][j]<float('INF'):
        return m[i][j]
    if i==j:
        m[i][j]=0
    else:
        for k in range(i,j):
            q=_Lookup_chain(m,p,i,k)+_Lookup_chain(m,p,k+1,j)+p[i-1]*p[k]*p[j]
            m[i][j]=q if q<m[i][j] else m[i][j]
    return m[i][j]


def LCS(X,Y):
    m=len(X)-1
    n=len(Y)-1
    b=[['#']*(n+1) for i in range(m+1)]
    c=[[0]*(n+1) for i in range(m+1)]

    for i in range(1,m+1):
        for j in range(1,n+1):
            if X[i]==Y[j]:
                c[i][j]=c[i-1][j-1]+1
                b[i][j]='wa'
            elif c[i-1][j]>=c[i][j-1]:
                c[i][j]=c[i-1][j]
                b[i][j]='w'
            else:
                c[i][j]=c[i][j-1]
                b[i][j]='a'
    return (c[m][n],b)

def print_LCS(b,X,i,j):
    if i==0 or j==0:
        return
    if b[i][j]=='wa':
        print_LCS(b,X,i-1,j-1)
        print(X[i],end=' ')
    elif b[i][j]=='w':
        print_LCS(b,X,i-1,j)
    else:
        print_LCS(b,X,i,j-1)

def memo(func):
    cache={}
    @wraps(func)
    def wrap(*args):
        if args not in cache:
            cache[args]=func(*args)
        return cache[args]
    return wrap


def max_sum_not_seq(p):
    @memo
    def m(i):
        #m(i)表示下标i以及之前所有元素的最大和（不一定连续！！！）
        if i<0:
            return 0
        val=max(m(i-1),p[i]+m(i-1))
        return val
    return m(len(p)-1)


def max_sum(p):
    max_value=this_value=0
    for x in p:
        this_value+=x
        max_value=this_value if this_value>max_value else max_value
        if this_value<0:
            this_value=0
    return max_value

def LCS_string(X,Y):
    m=len(X)-1
    n=len(Y)-1
    b = [['#'] * (n + 1) for i in range(m + 1)]
    c = [[0] * (n + 1) for i in range(m + 1)]

    for i in range(1,m+1):
        for j in range(1,n+1):
            if X[i]==Y[j]:
                c[i][j]=c[i-1][j-1]+1
                b[i][j]='wa'
            else:
                c[i][j]=0
    res=0
    px=py=0
    for x in range(1,m+1):
        for y in range(1,n+1):
            if res<c[x][y]:
                res=c[x][y]
                px=x
                py=y
    return (res,b,px,py)

def print_LCS_string(b,X,i,j):
    if i==0 or j==0:
        return
    if b[i][j]=='wa':
        print_LCS_string(b,X,i-1,j-1)
        print(X[i],end=' ')
    else:
        return

