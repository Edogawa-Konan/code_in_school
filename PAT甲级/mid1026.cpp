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

int N,K,M;
vector<People> p;
vector<Table> t;//K张桌子1~K


bool cmp(const People& o1,const People& o2)
{//根据到达时间进行排序
    return o1.arrive_time<o2.arrive_time;
}

bool cmp2(const People& o1,const People& o2)
{//根据服务开始时间进行排序
    return o1.serve_time<o2.serve_time;
}

int Find_next_vip(int vip)
{
    vip++;
    for (;vip!=p.size()&&p[vip].tag==0;vip++);
    return vip;
}

void Allocate_table(int current,int point)
{
    if(p[current].arrive_time<t[point].over_time)
    {
        p[current].serve_time=t[point].over_time;
    } else
    {
        p[current].serve_time=p[current].arrive_time;
    }
    t[point].over_time=p[current].play_time+p[current].serve_time;
    t[point].serve_count++;
}


int main()
{
    scanf("%d",&N);
    People tmp;
    for (int i=0,h,m,s,play;i<N;++i)
    {
        scanf("%d:%d:%d %d %d",&h,&m,&s,&play,&tmp.tag);
        tmp.arrive_time=h*3600+m*60+s;
        if(tmp.arrive_time>=21*3600)
            continue;
        tmp.serve_time=21*3600;//表示还没有被计算过
        tmp.play_time=play<120?play*60:7200;//最多2小时
        p.push_back(tmp);
    }
    scanf("%d %d",&K,&M);
    t.resize(K+1);
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

    int current=0,vip_index=-1;//当前队列的索引，下一个vip的索引
    vip_index=Find_next_vip(vip_index);
    while(current<p.size())
    {//对队伍进行遍历
        int point=0,min_end_time=999999;
        for (int i=1;i<=K;++i)
        {//用point指向最快结束的一桌
            if(t[i].over_time<min_end_time)
            {
                min_end_time=t[i].over_time;
                point=i;
            }
        }
        if(min_end_time>=21*3600)//打烊了，不再接待新顾客
            break;
        if(p[current].tag==1&&current<vip_index)
        {//中间优先安排的要过滤掉
            current++;
            continue;
        }
        if(t[point].tag==1)
        {//下一个是vip桌
            if(p[current].tag==1)
            {//正好下一个人是VIP
                Allocate_table(current,point);
                vip_index=Find_next_vip(vip_index);
                current++;
            }
            else
            {
                if(vip_index<p.size()&&p[vip_index].arrive_time<=t[point].over_time)
                {//如果队伍后面还有vip则优先安排它到这个桌子
                    Allocate_table(vip_index,point);
                    vip_index=Find_next_vip(vip_index);
                } else
                {
                    Allocate_table(current,point);
                    current++;
                }
            }
        }
        else
        {//下一桌不是VIP桌
            if(p[current].tag==0)
            {//下一个人也不是VIP
                Allocate_table(current,point);
                current++;
            } else
            {//下一个人是VIP
                int vip_point=-1,min_vip_end_time=99999999;
                for (int i=1;i<=K;++i)
                {
                    if(t[i].tag==1&&t[i].over_time<min_vip_end_time)
                    {
                        vip_point=i;
                        min_vip_end_time=t[i].over_time;
                    }
                }//先在vip桌中找，找不到就当作普通客人安排
                if(vip_point!=-1&&p[current].arrive_time>=min_vip_end_time)
                    Allocate_table(current,vip_point);
                else
                    Allocate_table(current,point);

                vip_index=Find_next_vip(vip_index);//更新下一个vip
                current++;
            }
        }
    }
    sort(p.begin(),p.end(),cmp2);
    for (int i=0;i<p.size()&&p[i].serve_time<21*3600;i++)
    {
        printf("%02d:%02d:%02d ",p[i].arrive_time/3600,p[i].arrive_time%3600/60,p[i].arrive_time%60);
        printf("%02d:%02d:%02d ",p[i].serve_time/3600,p[i].serve_time%3600/60,p[i].serve_time%60);
        printf("%.0f\n",round((p[i].serve_time-p[i].arrive_time)/60.0));
    }
    for (int i=1;i<=K;++i)
    {
        printf("%d",t[i].serve_count);
        if(i!=K)
            printf(" ");
    }
    return 0;
}



