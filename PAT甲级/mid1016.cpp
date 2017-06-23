//
// @author prime on 2017/6/6.
//


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Recode
{
    string name;
    int month,day,hour,minute,time;
    string status;//on or off?
};

bool compare(Recode & s1,Recode &s2)
{//一条比较语句可以包含很多信息
    return s1.name!=s2.name?s1.name<s2.name:s1.time<s2.time;
}


double calculate(const Recode &s,int const *cost, double a_day)
{
    double total=0;
    total+=cost[s.hour]*s.minute;
    for (int i=0;i<s.hour;i++)
        total+=60*cost[i];
    return (total+s.day*a_day)/100.0;
}

int main()
{
    int cost[24];
    for (int i=0;i<24;++i)
    {
        scanf("%d",&cost[i]);
    }
    int N;
    scanf("%d",&N);
    vector<Recode> input(N);//必须先预先分配足够的空间
    for(int i=0;i<N;++i)
    {
        cin>>input[i].name;
        scanf("%d:%d:%d:%d",&input[i].month,&input[i].day,&input[i].hour,&input[i].minute);
        input[i].time=input[i].day*24*60+input[i].hour*60+input[i].minute;
        cin>>input[i].status;
    }
    sort(input.begin(),input.end(),compare);
    map<string,vector<Recode>> res;
    vector<Recode>::iterator it=input.begin()+1,pre_it=input.begin();
    while(it!=input.end())
    {
        if(pre_it->name==it->name&&pre_it->status=="on-line"&&it->status=="off-line")
        {
            res[it->name].push_back(*pre_it);
            res[it->name].push_back(*it);
        }
        it++;
        pre_it++;
    }
    double a_day=0;//一天的消费
    for (int i=0;i<24;i++)
    {
        a_day+=cost[i]*60;
    }
    for (auto& e:res)
    {
        vector<Recode> tmp=e.second;
        cout<<e.first;
        printf(" %02d\n",tmp[0].month);
        double total=0;
        for (int i=0;i<tmp.size();i+=2)
        {
            printf("%02d:%02d:%02d %02d:%02d:%02d ",tmp[i].day,tmp[i].hour,tmp[i].minute,tmp[i+1].day,tmp[i+1].hour,tmp[i+1].minute);
            printf("%d ",tmp[i+1].time-tmp[i].time);
            double co=calculate(tmp[i+1],cost,a_day)-calculate(tmp[i],cost,a_day);
            printf("$%.2f\n",co);
            total+=co;
        }
        printf("Total amount: $%.2f\n",total);
    }
    return 0;
}


