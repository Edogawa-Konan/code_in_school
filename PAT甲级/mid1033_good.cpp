//
// @author prime on 2017/6/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Station
{
    double dis;//距离起点距离
    double per;//单位燃料价格
};

bool cmp(const Station& o1,const Station &o2)
{
    return o1.dis<o2.dis;
}

const double inf=9999999999;

int main()
{
    int C,D,avg,N;
    scanf("%d%d%d%d",&C,&D,&avg,&N);
    vector<Station> s(N);
    for (int i=0;i<N;++i)
    {
        scanf("%lf%lf",&s[i].per,&s[i].dis);
    }
    Station tmp;
    tmp.per=0,tmp.dis=D;
    s.push_back(tmp);
    sort(s.begin(),s.end(),cmp);
    const double can=C*avg;//加满油跑多远
    double cur_distance=0,cur_c=0,run_distance=0;//上个加油站的距离
    double total_cost=0,cur_per=s[0].per;
    if(s[0].dis>0)
    {
        printf("The maximum travel distance = %.2lf",0.0);
        return 0;
    }
    bool flag= false;//如果有比当前加油站更便宜的站，就为true

    int index=0;

    while(cur_distance<D)
    {
        run_distance=cur_distance+can;//当前最远跑到什么距离
        double min_per=inf;int point=-1;
        for (int i=index+1;i<s.size()&&s[i].dis<=run_distance;++i)
        {
            if(s[i].per<cur_per)
            {
                point=i;
                flag= true;
                break;
            }
            if(s[i].per<min_per)
            {
                min_per=s[i].per;
                point=i;
            }
        }//point始终指向最适合的下一个加油站！
        if(!flag&&min_per==inf)
        {
            printf("The maximum travel distance = %.2lf",run_distance);
            return 0;
        }
        if(flag)
        {//存在比当前更便宜的加油站，而且可以直达
            total_cost+=((s[point].dis-cur_distance)/avg-cur_c)*cur_per;

            cur_c=0.0;//直接把油用完
        }
        if(!flag&&min_per!=inf)
        {//不存在比当前加油站更便宜的啦，所以我要加满！
            total_cost+=(C-cur_c)*cur_per;

            cur_c=C-(s[point].dis-cur_distance)/avg;
        }
        cur_distance=s[point].dis;
        cur_per=s[point].per;
        index=point;
        flag= false;
    }
    printf("%.2lf",total_cost);
    return 0;
}


//
// @author prime on 2017/6/17.
//



