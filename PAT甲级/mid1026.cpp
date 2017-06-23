//
// @author prime on 2017/6/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct Table
{
    int over_time;//结束时间
    int serve_count;//服务人数
    int tag;//VIP桌？
};

struct People
{
    int arrive_time;
    int tag;
    int serve_time;//开始服务时间
    int play_time;//玩了多久
};
bool cmp(const People& o1,const People& o2)
{
    return o1.arrive_time<o2.arrive_time;
}

bool cmp2(const People& o1,const People& o2)
{
    return o1.serve_time<o2.serve_time;
}

int main()
{
    int N,K,M;
    scanf("%d",&N);
    vector<People> p(N);
    for (int i=0,h,m,s,play;i<N;++i)
    {
        scanf("%d:%d:%d %d %d",&h,&m,&s,&play,&p[i].tag);
        p[i].arrive_time=h*3600+m*60+s;
        p[i].serve_time=-2;//表示还没有被计算过
        p[i].play_time=play*60;
    }
    scanf("%d %d",&K,&M);
    vector<Table> t(K+1);
    for (auto & e:t)//桌子们初始化
    {
        e.over_time=8*3600;//一开始所有桌子的结束时间初始化8时
        e.serve_count=0;
        e.tag=0;
    }
    for (int i=1,num;i<=M;i++)
    {
        scanf("%d",&num);
        t[num].tag=1;
    }

    sort(p.begin(),p.end(),cmp);//按照来的顺序排队

    for (int current=0;current<N;++current)
    {//current是用户指针
        if(p[current].serve_time!=-2)
            continue;
        int fast=99999999,point=-1;//point是桌子编号
        for (int i=1;i<=K;i++)
        {
            if(t[i].over_time<fast)
            {
                fast=t[i].over_time;
                point=i;
            }
        }
        if(fast>=21*3600)
        {
            break;//后面的无法被服务了
        }
        if(p[current].arrive_time<t[point].over_time)
        {//需要排队时
            if(t[point].tag==1)
            {//这个桌子是vip桌，看看有没有vip在排队
                for (int i=current;i<N&&p[current].arrive_time<t[point].over_time;++i)
                {
                    if(p[i].tag==1)
                    {
                        p[i].serve_time=t[point].over_time;
                        t[point].over_time+=p[i].play_time;
                        t[point].serve_count++;
                        current--;//服务vip了，这个人就没被服务，
                        goto next;
                    }
                }
            }
            p[current].serve_time=t[point].over_time;//因为需要排队，开始服务时间就是轮到他的时候
            t[point].over_time+=p[current].play_time;
            t[point].serve_count++;
        }
        else
        {
            p[current].serve_time=p[current].arrive_time;//不需要排队时，开始服务时间就是到达时间
            t[point].over_time=p[current].arrive_time+p[current].play_time;//这一点注意
            t[point].serve_count+=1;
        }
        next:
        continue;
    }

    sort(p.begin(),p.end(),cmp2);

    for (int i=0;i<N;++i)
    {
        if(p[i].serve_time==-2)
            continue;
        printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",p[i].arrive_time/3600,
               p[i].arrive_time%3600/60,p[i].arrive_time%60,p[i].serve_time/3600,p[i].serve_time%3600/60,
               p[i].serve_time%60,round((p[i].serve_time-p[i].arrive_time)/60.0));
    }
    for (int i=1;i<=K;i++)
    {
        if(i!=1)
            printf(" ");
        printf("%d",t[i].serve_count);
    }
    return 0;
}



