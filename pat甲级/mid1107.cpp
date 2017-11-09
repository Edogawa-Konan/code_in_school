//
// @author prime on 2017/7/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> father;
int tmp[1001];//记录爱好i的人的编号

int get_father(int v)
{
    int p=v;
    while(p!=father[p])
        p=father[p];//p指向v的根节点
    while(v!=father[v])
    {
        int tmp=v;
        v=father[v];
        father[tmp]=p;
    }
    return p;
}


void union_father(int x,int y)
{
    int fx=get_father(x);
    int fy=get_father(y);
    if(fx!=fy)
        father[fy]=fx;
}


int main()
{
    int N;
    scanf("%d",&N);
    father.resize(N+1);
    vector<int> res(N+1);
    for (int i=1;i<=N;++i)
        father[i]=i;//每个人先独立
    for (int i=1;i<=N;++i)
    {
        int k,hobby;
        scanf("%d:",&k);
        for (int j=0;j<k;++j)
        {
            scanf("%d",&hobby);
            if(tmp[hobby]==0)
            {
                tmp[hobby]=i;
                continue;
            }
            union_father(i,tmp[hobby]);
        }
    }
    for (int i=1;i<=N;++i)
        res[get_father(i)]++;
    int count=0;
    for (int i=1;i<=N;++i)
    {
        if(res[i]>0)
            count++;
    }
    sort(res.begin(),res.end(),greater<int>());
    printf("%d\n",count);
    for (int i=0;i<count;i++)//注意排序全排序，所以最大的在下标0
    {
        printf("%d",res[i]);
        if(i!=count-1)
            printf(" ");
    }
    return 0;
}


