# -*- coding:utf-8 -*-
# -*- by prime -*-

from functools import wraps
def memo(func):
    cache={}
    @wraps(func)
    def wrap(*args):
        if args not in cache:
            cache[args]=func(*args)
        return cache[args]
    return wrap

#完全背包问题
def rec_unbounded_knapsack(w,v,c):
    @memo
    def m(r):
        #当前背包剩余容量为r时最大价值
        if r==0:
            return 0
        val=m(r-1)
        for i,e in enumerate(w):
            if e>r:
                continue
            val=max(val,v[i]+m(r-w[i]))
        return val
    return m(c)

def unbounded_knapsack(w,v,c):
    m=[0]*(c+1) #m[r]表示当前背包剩余容量为r时最大价值
    for r in range(1,c+1):
        val=m[r-1]
        for i,e in enumerate(w):
            if e>r:
                continue
            val=max(val , v[i]+m[r-w[i]])
        m[r]=val
    return m[c]



#0-1背包问题
def knapsack(w,v,c):
    n=len(w)
    m=[[0]*(c+1) for i in range(n+1)]
    for k in range(1,n+1):
        for r in range(1,c+1):
            if w[k-1]>r:
                m[k][r]  = m[k-1][r]
            else:
                m[k][r]=max(m[k-1][r],m[k-1][r-w[k-1]]+v[k-1])
    return m[n][c]



def rec_knapsack(w,v,c):
    @memo
    def m(k,r):
        #设前k个对象的最大价值,r是剩余背包容量
        if k==0 or r==0:
            return 0
        drop=m(k-1,r) #当丢掉最后一个对象时的价值
        if w[k-1]>r:
            return drop #必须丢掉它
        return max(drop,v[k-1]+m(k-1,r-w[k-1]))
    return m(len(w),c)


def fractional_knapsack(w,v,c):
    item=[]
    for weight,value in zip(w,v):
        item.append({'weight':weight,'value':value,'ratio':value/weight})
    item.sort(key=lambda x:x['ratio'],reverse=True)#默认从小到大排序
    print(item)
    total=0
    for x in item:
        if c>x['weight']:
            c-=x['weight']
            total+=x['value']
        else:
            total+=(c/x['weight'])*x['ratio']
            break
    return total




if __name__ == '__main__':
    w=[10,20,30,40,50]
    v=[20,30,65,40,60]
    c=100
    # print(rec_knapsack(w,v,c))
    # print(knapsack(w,v,c))
    # print(unbounded_knapsack(w,v,c))
    # print(rec_unbounded_knapsack(w,v,c))
    print(fractional_knapsack(w,v,c))



