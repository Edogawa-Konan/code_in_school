//
// @author prime on 2017/8/3.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int father[10000];
bool exist[10000];

/*这里不用路径压缩了，因为id大小是确定的，大的id当小的儿子*/
int Find(int x)
{
    while (x!=father[x])
        x=father[x];
    return x;
}

void Union(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx>fy)
        father[fx]=fy;
    else
        father[fy]=fx;
}

struct Node
{
    int id;
    int mother,father;
    int num,area;//房产数量、房产面积
    vector<int> child;
};

struct Cluster
{
    int id;//最小的id
    int member,sets,area;
    bool valid;
};

bool cmp(const Cluster&o1,const Cluster&o2)
{
    if(o1.valid!=o2.valid)//先判断是否有效，不然可能分母为0
        return o1.valid>o2.valid;
    else
    {
        double a=1.0*o1.area/o1.member,b=1.0*o2.area/o2.member;
        if(a!=b)
            return a>b;
        else
            return o1.id<o2.id;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    vector<Node> a(N);
    for (int i=0;i<10000;i++)//并查集初始化，千万别忘了~~~
        father[i]=i;
    for (int i=0;i<N;++i)
    {
        int k,child;
        scanf("%d %d %d %d",&a[i].id,&a[i].mother,&a[i].father,&k);
        exist[a[i].id]=true;
        if(a[i].father!=-1)
        {
            exist[a[i].father]=true;
            Union(a[i].father,a[i].id);
        }
        if(a[i].mother!=-1)
        {
            exist[a[i].mother]=true;
            Union(a[i].mother,a[i].id);
        }
        for(int j=0;j<k;++j)
        {
            scanf("%d",&child);
            exist[child]=true;
            Union(a[i].id,child);
            a[i].child.push_back(child);
        }
        scanf("%d %d",&a[i].num,&a[i].area);
    }
    vector<Cluster> res(10000);
    for (int i=0;i<N;i++)
    {
        int f=Find(a[i].id);
        res[f].id=f;
        res[f].sets+=a[i].num;
        res[f].area+=a[i].area;
        res[f].valid=true;
    }
    int count=0;//集群的个数
    for (int i=0;i<10000;i++)//直接对id遍历
    {
        if(exist[i])
            res[Find(i)].member++;//老办法，统计并查集中元素个数
        if(res[i].valid)
            count++;//统计集群个数
    }
    printf("%d\n",count);
    sort(res.begin(),res.end(),cmp);
    for (int i=0;i<count;i++)
    {
        printf("%04d %d %.3f %.3f\n",res[i].id,res[i].member,1.0*res[i].sets/res[i].member,1.0*res[i].area/res[i].member);
    }
    return 0;
}



