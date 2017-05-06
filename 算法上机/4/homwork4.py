# -*- coding:utf-8 -*-
# -*- by prime -*-

import pp,time


def knapsack(w,v,c):
    current_v = 0
    current_w = 100
    max_v = 0
    n=len(w)
    def dfs(i):
        nonlocal current_v
        nonlocal current_w
        nonlocal max_v
        if i==n:
            max_v=current_v if current_v>max_v else max_v
            return max_v
        if current_w>=w[i]:
            current_w-=w[i]
            current_v+=v[i]
            dfs(i+1)
            current_v-=v[i]
            current_w+=w[i]
        return dfs(i+1)

    return dfs(0)

def queen(n):
    C=[0]*n #表示第i行的皇后放第几列
    res=0 #解的个数
    def dfs(current):
        nonlocal C
        nonlocal res
        if current==n:
            res+=1
            # print(C)
        else:
            for i in range(0,n):
                flag=True
                C[current]=i
                for j in range(0,current):
                    if C[j]==C[current] or current-C[current]==j-C[j] or current+C[current]==j+C[j]:
                        flag=False
                        break
                if flag:
                    dfs(current+1)
    dfs(0)
    return res



if __name__ == '__main__':
    # w = [10, 20, 30, 40, 50]
    # v = [20, 30, 65, 40, 60]
    # c = 100
    # print(knapsack(w,v,c))

    start=time.time()
    # print(queen(12))
    print(queen(10))
    # print(queen2(10))
    print('总共用时:',time.time()-start,'s')

    # job=pp.Server(ppservers=())
    # # print(job.get_ncpus())
    # res=[job.submit(queen,(x,)) for x in (12,12)]
    #
    # '''
    # f1 = job_server.submit(func1, args1, depfuncs1, modules1)
    # #func1: 被并行执行的函数
    # #args1: func的参数，以元组的形式传入
    # #depfuncs1: 被func调用的函数，以元组的形式传入
    # #modules1: 函数执行需要调用的模块，以元组的形式传入
    # '''
    # for x in res:
    #     print(x())
    # job.print_stats()





