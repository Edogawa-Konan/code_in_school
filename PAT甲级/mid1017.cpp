//
// @author prime on 2017/6/6.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Customer
{
    int arrive;
    int take;
};

bool cmp(const Customer& s1,const Customer &s2)
{
    return s1.arrive<s2.arrive;
}

int main()
{
    int N,K;//N个顾客,K个窗口
    scanf("%d %d",&N,&K);
    vector<Customer> c;
    for (int i=0;i<N;++i)
    {
        int hh,mm,ss,tt;
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&tt);
        int s=hh*3600+mm*60+ss;
        if(s>61200)//5点之后来的不被服务
            continue;
        Customer tmp;
        tmp.arrive=s;
        tmp.take=tt*60;
        c.push_back(tmp);
    }
    if(c.size()==0)
    {
        printf("0.0");
        return 0;
    }
    int window[K]={28800};//每个窗口的结束时间 fuck，这个只初始化第一个元素。！！！！！！
    fill(window,window+K,28800);
    sort(c.begin(),c.end(),cmp);
    double total_time=0.0;
    for(int index=0;index<c.size();++index)
    {
        int fast=window[0],point=0;
        for (int i=1;i<K;++i)
        {
            if(window[i]<fast)
            {
                fast=window[i];
                point=i;
            }
        }
        if(window[point]<=c[index].arrive)//窗口结束时间早于顾客来,不用等待
        {
            window[point]=c[index].arrive+c[index].take;
        } else
        {
            total_time+=(window[point]-c[index].arrive);//需要等待
            window[point]+=c[index].take;//窗口结束时间增加
        }
    }
    printf("%.1f",total_time/60.0/c.size());
    /*printf("\nsize= %lld\n",c.size());
    for (auto &e:c)
    {
        printf("%d %d\n",e.arrive,e.take);
    }
    printf("\n%f",total_time);*/
    return 0;
}
