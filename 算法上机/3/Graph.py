# -*- coding:utf-8 -*-
# -*- by prime -*-
from collections import deque
from copy import deepcopy
import sys

class DepthFirstOrder(object):
    def __init__(self,G):
        self.old=set() #记录已经被遍历过的节点
        self.pre=[]
        self.post=[]
        self.reversePost=[]

        for x in G:
            if x not in self.old:
                self.dfs(G,x)

        self.reversePost.reverse()#原地反转返回None
    def dfs(self,G,v):
        self.pre.append(v)

        self.old.add(v)
        for w in G[v]:
            if w not in self.old:
                self.dfs(G,w)

        self.post.append(v)
        self.reversePost.append(v)
    def topo(self):
        return self.reversePost


def Topo_shortest_path(G,v):
    #适用于有向无环图，可以有负权
    path={}
    dis=dict((k,float('inf'))for k in G)
    dis[v]=0
    topo=DepthFirstOrder(G).topo()

    for x in topo:
        #按照拓扑排序的结果对顶点松弛
        for w in G[x]:
            if dis[w]>dis[x]+G[x][w]:
                dis[w]=dis[x]+G[x][w]
                path[w]=x
    return dis

def SPFA(G,v):
    '''
    利用 spfa 算法判断负环有两种方法：

      1） spfa 的 dfs 形式，判断条件是存在一点在一条路径上出现多次。

      2） spfa 的 bfs 形式，判断条件是存在一点入队次数大于总顶点数。
    :param G: 图
    :param v: 起点
    :return: dis,path
    '''
    #用队列优化Bellman-Ford算法，这里不能有负环，程序中没有判断。
    q=deque()
    path={}#用于打印路径
    dis=dict((k,float('inf'))for k in G)#记录距离
    dis[v]=0
    times=dict((k,0) for k in G)#用于记录每个顶点入队列的次数，如果大于顶点个数表明有负环
    q.append(v)#起始把起点入队
    while len(q)!=0:
        x=q.popleft()#出队一个
        #对该顶点所有的邻边进行松弛
        for w in G[x]:
            if dis[w]>dis[x]+G[x][w]:
                dis[w]=dis[x]+G[x][w]
                path[w]=x #记录此顶点的上一个顶点
                if w not in q:
                    if times[w]>len(G):
                        sys.exit('存在负环，嗝屁了')
                    q.append(w)
                    times[w]+=1
    return dis,path


def Bellman_Ford(G,v):
    '''
    每一轮对所有顶点进行松弛，如果哪一轮松弛后最短距离都不变化就提前结束。否则，如果执行n
    轮之后还在变化则说明存在负环。最多n-1次松弛就可以得到答案。（n为顶点个数）
    :param G: 图的邻接表
    :param v: 起点
    :return: dis,path
    '''
    dis=dict((k,float('inf'))for k in G)
    dis[v]=0
    path={}
    for rounds in G:#一共执行n次，如果n次之后最短路径还没求出来说明有负环
        changed=False
        #对所有顶点进行松弛
        for u in G:
            for w in G[u]:
                if dis[w] > dis[u] + G[u][w]:
                    dis[w] = dis[u] + G[u][w]
                    path[w] = u
                    changed=True
        if not changed:
            break
    else:
        sys.exit('存在负环，算法求不出来')
    return dis,path

def Folyd_Warshall(G):
    G2=deepcopy(G)
    #强行补成邻接矩阵的形式
    for u in G2:
        for v in G2:
            if u==v:
                G2[u][v]=0
            if G2[u].get(v)==None:
                G2[u][v]=float('inf')

    for k in G:
        for u in G:
            for v in G:
                if G2[u][v]>G2[u][k]+G2[k][v]:
                    G2[u][v]=G2[u][k]+G2[k][v]
    return G2



def print_path(dis,path):
    for x in path:
        print('到顶点',x,'的总长度为:',dis[x],'具体的路径为',end=': ')
        t=x
        while t!=None:
            print(t,"<-",end=' ')
            t=path.get(t)
        print()

























































































































































































































































































































































































































































































































































































































































































































