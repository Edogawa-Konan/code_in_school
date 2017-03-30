# -*- coding:utf-8 -*-
# -*- by prime -*-

import random
from homwork1 import quick_sort,Priority_Queue,find_kth_largest
import cProfile
import pstats

L1=random.sample(range(1000),500)
L2=L1[:]
print('原随机数序列: ')
print(L1)

pro=cProfile.Profile()
pro.enable()

quick_sort(L2,0,len(L2)-1)
print('快排之后: ')
print(L2)

pq=Priority_Queue(L1)
print('优先级队列最大元素： ')
print(pq.getmax())
print('堆排序: ')
pq.sort()
pq.show()

A=[300,200,69,55,19,15,13]
B=[250,100,99,79,25,16,7]
print('找出第k大的元素，默认从大到小有序:')
print('A: ',A)
print('B: ',B)
print(find_kth_largest(A,B,2))


print('分析报告如下')
pro.print_stats()
