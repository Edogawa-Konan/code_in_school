//
// @author prime on 2017/6/5.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &o1,const vector<int>&o2)
{
    auto end=min(o1.size(),o2.size());
    for (int i=0;i<end;++i)
    {
        if(o1[i]>o2[i])
            return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> a;
    a.push_back({1,2});
    a.push_back({1,2,3});
    a.push_back({5,4});
    sort(a.begin(),a.end(),cmp);
    for(auto & arr:a)
    {
        for (auto& e:arr)
        {
            printf("%d ",e);
        }
        printf("\n");
    }
    return 0;
}