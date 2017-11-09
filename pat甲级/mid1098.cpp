//
// @author prime on 2017/7/27.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void sink(vector<int> &partial,int parent,int length)
{//顶点元素下沉
    int child=2*parent;
    while(child<=length)
    {
        if(child<length&&partial[child+1]>partial[child])
            child=child+1;
        if(partial[parent]>=partial[child])
            break;
        swap(partial[child],partial[parent]);
        parent=child;
        child=parent*2;
    }
}


int main()
{
    int N;
    scanf("%d",&N);
    vector<int> init(N+1),partial(N+1);
    for (int i=1;i<=N;++i)
        scanf("%d",&init[i]);
    for (int i=1;i<=N;++i)
        scanf("%d",&partial[i]);
    int i,j;
    for (i=1;i<N&&partial[i]<=partial[i+1];i++);//i指向最后一个有序的元素
    for(j=i+1;j<=N&&partial[j]==init[j];j++);
    if(j==N+1)
    {
        printf("Insertion Sort\n");
        sort(partial.begin()+1,partial.begin()+1+i+1);
    }
    else
    {
        printf("Heap Sort\n");
        for(i=N;i>1&&partial[i]>=partial[i-1];i--);//i指向堆的最后一个元素
        swap(partial[1],partial[i]);
        sink(partial,1,i-1);
    }
    for(int i=1;i<=N;++i)
    {
        printf("%d",partial[i]);
        if(i!=N)
            printf(" ");
    }
    return 0;
}



