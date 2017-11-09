//
// @author prime on 2017/7/1.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Mooncake
{
    double inventory;
    double price;
    double rate;//性价比
};

bool cmp(const Mooncake&o1,const Mooncake&o2)
{
    return o1.rate>o2.rate;
}

int main()
{
    int N,D;
    scanf("%d%d",&N,&D);
    vector<Mooncake> s(N);
    for (int i=0;i<N;i++)
    {
        scanf("%lf",&s[i].inventory);
    }
    for (int i=0;i<N;++i)
    {
        scanf("%lf",&s[i].price);
        s[i].rate=s[i].price/s[i].inventory;
    }
    sort(s.begin(),s.end(),cmp);
    double total_profit=0;
    for (int i=0;i<N;++i)
    {
        if(s[i].inventory>D)
        {
            total_profit+=D*s[i].rate;
            break;
        }
        else
        {
            D-=s[i].inventory;
            total_profit+=s[i].price;
        }
    }
    printf("%.2lf",total_profit);
    return 0;
}

