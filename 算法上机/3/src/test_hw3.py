# -*- coding:utf-8 -*-
# -*- by prime -*-

from homwork3 import schedule,knapsack,fractional_knapsack,SPFA,print_path,Bellman_Ford,Folyd_Warshall

# w = [10, 20, 30, 40, 50]
# v = [20, 30, 65, 40, 60]
# c = 100
#
# print('0-1背包的结果:',knapsack(w,v,c))
#
# print('分数背包问题的结果:',fractional_knapsack(w, v, c))
#
# a=[15,8,3,10]
# print('调度问题的结果',schedule(a))


G={'A':{'B':-1,'C':3},
   'B':{'C':3,'D':2,'E':2},
   'C':{},
   'D':{'B':1,'C':5},
   'E':{'D':-3}
   }
# print('SPFA算法:')
# print_path(*SPFA(G,'A'))
# print('-'*50)
# print('Bellman-Ford算法:')
# print_path(*Bellman_Ford(G,'A'))
print('Folyd-Warshall:')
res=Folyd_Warshall(G)
for x in res:
    print(x,res[x])