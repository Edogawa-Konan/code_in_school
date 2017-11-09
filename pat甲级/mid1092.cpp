//
// @author prime on 2017/7/25.
//
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string shop,eva;
    cin>>shop>>eva;
    unordered_map<char,int> m;
    for (auto &e:shop)
        m[e]++;
    int miss=0;
    for (auto&e:eva)
    {
        if(m[e]==0)
            miss++;
        else
            m[e]--;
    }
    if(miss>0)
        cout<<"No "<<miss;
    else
    {
        int extra=0;
        for(auto&it:m)
        {
            extra+=it.second;
        }
        cout<<"Yes "<<extra;
    }
    return 0;
}



