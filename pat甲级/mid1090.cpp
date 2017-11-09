//
// @author prime on 2017/7/25.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,vector<int>> stor;
double max_price=0;
int total=0;
double p,r;

void DFS(int u,double price)
{
    if(stor[u].empty())
    {
        if(price>max_price)
        {
            max_price=price;
            total=1;
        }
        else if(price==max_price)
            total++;
    }
    else
    {
        for(int i=0;i<stor[u].size();i++)
            DFS(stor[u][i],price*(1.0+r));
    }
}

int main()
{
    int N;
    cin>>N>>p>>r;
    r/=100;
    for (int i=0;i<N;++i)
    {
        int supplier;
        cin>>supplier;
        stor[supplier].push_back(i);
    }
    DFS(-1,p);
    max_price/=(1+r);//注意这里之所以除以一次，是因为我们从根结点出发的，根节点的下级本应是p，但是算成了p(1+r)，所以多乘了一次。
    printf("%.2lf %d",max_price,total);
    return 0;
}

