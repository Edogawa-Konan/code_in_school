# -*- coding:utf-8 -*-
# -*- by prime -*-

def find_kth_largest(A,B,k):
    if len(A)==0:
        return B[k-1]
    if len(B)==0:
        return A[k-1]
    i=len(A)//2
    j=len(B)//2
    if B[j]<A[i]:
        A,B=B,A
        i,j=j,i
    t=i+j+1
    if k<=t:
        return find_kth_largest(A[:i],B,k)
    else:
        return find_kth_largest(A,B[j+1:],k-j-1)

class Priority_Queue(object):
    '''
        length从1到最后一个元素，0空出来没用
    '''
    def __init__(self):
        self.pq = [0] * 101
        self.length = 0  # 优先队列
        self.real_len = 0  # 堆排序
    def __init__(self, a):
        if isinstance(a, list):  # isinstance和java中instanceof一样，用type就对子类无效了
            self.pq = a[:]
            self.real_len = self.length = len(a)
            self.pq[self.length:] = [0]
            self.pq[1:] = self.pq[:]  # 空出第一个元素
            # for index,value in enumerate(self.pq):
            #     self.__swim(index)
            for i in range(1,self.length+1):
                self.__swim(i)
    def size(self):
        return self.length
    def isempty(self):
        return self.length == 0
    def insert(self, v):
        self.length += 1
        self.real_len += 1
        if self.length > 100:
            self.pq.extend([0] * 100)
        self.pq[self.length] = v
        self.__swim(self.length)  # 每当加入一个元素，都应该从它开始上浮到它该待的地方
    def __swim(self,k):
        ##大顶堆，大的上浮
        while k>1 and self.pq[k//2]<self.pq[k]:
            self.pq[k],self.pq[k//2]=self.pq[k//2],self.pq[k]
            k=k//2
    def __sink(self,k):
        #j是儿子，k是爹
        j=2*k
        while j<=self.length :
            #让j指向较大的儿子
            if j< self.length and self.pq[j]<self.pq[j+1]:
            # j<self.length一定要有，防止2*k是最后一个元素了
                j+=1
            #如果爹不比儿子们小，那就下沉结束了
            if not self.pq[k]<self.pq[j]:
                break
            self.pq[k],self.pq[j]=self.pq[j],self.pq[k]
            k=j
            j=2*k
    def getmax(self):
        return self.pq[1]
    def delmax(self):
        #最大的放最后面了
        self.pq[1],self.pq[self.length]=self.pq[self.length],self.pq[1]
        self.length -= 1
        self.__sink(1)
        return self.pq[self.length+1]
    def show(self):
        print(self.pq[1:self.real_len+1])
        print('length==',self.length)
        print('real_length=',self.real_len)
        print('-'*100)
    def sort(self):
        for i in range(self.length,1,-1):
            self.delmax()

def _partition(a,low,high):
    #供quick_sort调用
    i=low+1
    j=high
    v=a[low]
    while True:
        while a[i]<v:
            i+=1
            if i>high:
                break
        while a[j]>v:
            j-=1
            if j<low:
                break
        if i>=j:
            break
        a[i],a[j]=a[j],a[i]
    a[low],a[j]=a[j],a[low]
    return j


def quick_sort(array,start,end):
    if start<end:
        mid=_partition(array,start,end)
        quick_sort(array,start,mid-1)
        quick_sort(array,mid+1,end)


if __name__ == '__main__':
    A=[300,200,69,55,19,15,13]
    B=[250,100,99,79,25,16,7]
    print(find_kth_largest(A,B,2))
