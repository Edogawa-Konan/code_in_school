//
// @author prime on 2017/8/4.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> father(10010,0);

int Find(int x)
{
    int parent=x;
    while (parent!=father[parent])
        parent=father[parent];
    while (x!=father[x])
    {
        int tmp=x;
        x=father[x];
        father[tmp]=parent;
    }
    return x;
}

void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
        father[fx]=fy;
}


int main()
{
    vector<bool> exist(10010, false);//记录下标为i的鸟是否出现
    for (int i=0;i<10010;++i)//并查集初始化
        father[i]=i;
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;++i)
    {
        int k,bird,first;
        scanf("%d %d",&k,&first);//first单独记录第一个鸟，为了合并集合
        exist[first]=true;
        for (int j=1;j<k;++j)
        {
            scanf("%d",&bird);
            exist[bird]=true;
            Union(first,bird);
        }
    }
    vector<int> count(10010,0);//计算以i为根的并查集中元素个数
    int num_tree=0,num_bird=0;
    for (int i=1;i<10010;i++)
    {
        if(exist[i])
        {
            num_bird=i;
            count[Find(i)]++;
        }
    }
    for (int i=1;i<10010;++i)
    {
        if(count[i]>0)
            num_tree++;
    }
    printf("%d %d\n",num_tree,num_bird);
    int Q;
    scanf("%d",&Q);
    for (int i=0;i<Q;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(Find(x)==Find(y))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}



