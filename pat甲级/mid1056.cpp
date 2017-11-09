//
// @author prime on 2017/6/27.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct Mouse
{
    int input_order;
    int index;//参赛顺序
    int weight;
    int rank;
};


bool cmp(const Mouse&o1,const Mouse&o2)
{
    return o1.input_order<o2.input_order;
}

int main()
{
    int Np,Ng;
    scanf("%d%d",&Np,&Ng);
    vector<int> we(Np);
    vector<Mouse> m(Np);
    for (int i=0;i<Np;++i)
    {
        scanf("%d",&we[i]);
    }
    for (int i=0,num;i<Np;++i)
    {
        scanf("%d",&num);
        m[i].weight=we[num];
        m[i].input_order=num;
        m[i].index=i;
    }
    deque<Mouse> q;
    for (int i=0;i<Np;++i)
        q.push_back(m[i]);
    while(!q.empty())
    {
        int len=q.size();
        if(len==1)
        {
            m[q[0].index].rank=1;
            break;
        }
        int group=len/Ng;
        if(len%Ng!=0)
            group++;//一共需要分成几组
        int count=0;//每一小组人的计数
        int max_weight=-1;
        int point=-1;//指向每个小组最重的那个
        for (int i=0;i<len;++i)
        {
            Mouse tmp=q[0];
            m[tmp.index].rank=group+1;
            q.pop_front();
            count++;

            if(tmp.weight>max_weight)
            {
                max_weight=tmp.weight;
                point=tmp.index;
            }
            if(count==Ng||i==len-1)
            {//小组进行完或者最后一个小组进行完
                q.push_back(m[point]);
                count=0;
                max_weight=-1;
                point=-1;
            }
        }
    }
    sort(m.begin(),m.end(),cmp);
    for (int i=0;i<m.size();++i)
    {
        if(i!=m.size()-1)
            printf("%d ",m[i].rank);
        else
            printf("%d",m[i].rank);
    }
    return 0;
}


