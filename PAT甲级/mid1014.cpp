//
// @author prime on 2017/6/6.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;


struct Window
{
    deque<int> q;
    int first_over;//队列第一个结束的时间
    int last_over;//队列最后一个结束的时间
};

int main()
{
    int N,M,K,Q;
    scanf("%d %d %d %d",&N,&M,&K,&Q);
    vector<int> time(K+1);
    vector<bool> sorry(K+1, false);
    int index=1;//处理到第几个顾客
    vector<int> res(K+1);
    for(int i=1;i<=K;++i)
    {
        scanf("%d",&time[i]);
    }
    vector<Window> w(N+1);
    for (int i=1;i<=M;++i)//队列中每一个
    {
        for (int j=1;j<=N;++j)//每个窗口
        {
            if(index<=K)
            {
                if(w[j].last_over>=540)//思维漏洞，没考虑黄线内的可能也会sorry
                {
                    sorry[index]= true;
                    goto xixi;
                }
                w[j].q.push_back(time[index]);
                w[j].last_over+=time[index];
                if(i==1)
                {//每队的第一个结束时间
                    w[j].first_over=time[index];
                }
                res[index]=w[j].last_over;//每次都是从最后开始排队，队伍结束就是自己结束
                xixi:
                    index++;
            }
        }
    }
    while(index<=K)
    {//有人在黄线外
        int min_time=w[1].first_over;
        int point=1;//记录下标
        for (int i=2;i<=N;++i)
        {
            if(w[i].first_over<min_time)
            {
                min_time=w[i].first_over;
                point=i;
            }
        }
        if(w[point].last_over>=540)
        {
            sorry[index]= true;
            goto hehe;
        }
        w[point].q.pop_front();
        w[point].q.push_back(time[index]);
        w[point].first_over+=w[point].q[0];
        w[point].last_over+=time[index];
        res[index]=w[point].last_over;
        hehe:
            ++index;
    }
    for (int i=1,check;i<=Q;++i)
    {
        scanf("%d",&check);
        if(sorry[check])
            printf("Sorry\n");
        else
        {
            int hour,minute;
            minute=res[check]%60;
            hour=res[check]/60;
            printf("%02d:%02d\n",hour+8,minute);
        }
    }
    return 0;
}




