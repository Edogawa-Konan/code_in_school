//
// @author prime on 2017/7/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

struct Car
{
    int symbol;//1表示in，-1表示out
    int time;
    char id[10];
};

bool cmp(const Car&o1,const Car&o2)
{
    if(strcmp(o1.id,o2.id)==0)
        return o1.time<o2.time;
    else
        return strcmp(o1.id,o2.id)<0;
}
bool cmp2(const Car&o1,const Car&o2)
{
    return o1.time<o2.time;
}

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    vector<Car> c(N);
    for (int i=0;i<N;++i)
    {
        char tmp[4];
        int h,m,s;
        scanf("%s %d:%d:%d %s",c[i].id,&h,&m,&s,tmp);
        c[i].time=h*3600+m*60+s;
        if(strcmp(tmp,"in")==0)
            c[i].symbol=1;
        else
            c[i].symbol=-1;
    }
    sort(c.begin(),c.end(),cmp);
    map<string,int> dict;//id——停车时间
    vector<Car> t;
    int longest=0;//记录最长的停车时间
    for (int i=0;i<N-1;i++)
    {
        if(strcmp(c[i].id,c[i+1].id)==0&&c[i].symbol==1&&c[i+1].symbol==-1)
        {
            t.push_back(c[i]);
            t.push_back(c[i+1]);
            dict[c[i].id]+=c[i+1].time-c[i].time;
            if(dict[c[i].id]>longest)
                longest=dict[c[i].id];
        }
    }
    sort(t.begin(),t.end(),cmp2);
    vector<int> count(t.size());//记录每个时间点的车数量
    for (int i=0;i<t.size();++i)
    {
        if(i==0)
            count[i]=t[0].symbol;
        else
            count[i]=count[i-1]+t[i].symbol;
    }
    int index=0;
    for(int i=0;i<K;++i)
    {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        int time=h*3600+m*60+s;
        for(int j=index;j<count.size();j++)
        {
            if(time<t[j].time)
            {
                printf("%d\n",count[j-1]);
                index=j;
                break;
            }
            else if(j==count.size()-1)
            {
                printf("%d\n",count[j]);
                index=j;
            }
        }
    }
    for(auto&p:dict)
    {
        if(p.second==longest)
        {
            printf("%s ",p.first.c_str());
        }
    }
    printf("%02d:%02d:%02d",longest/3600,longest%3600/60,longest%60);
    return 0;
}

