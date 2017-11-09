//
// @author prime on 2017/6/25.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    vector<string> res[K+1];
    for (int i=0,c;i<N;++i)
    {
        string name;
        cin>>name;
        scanf("%d",&c);
        for (int j=0,index;j<c;++j)
        {
            scanf("%d",&index);
            res[index].push_back(name);
        }
    }
    for (int i=1;i<=K;i++)
    {
        printf("%d %d\n",i,res[i].size());
        sort(res[i].begin(),res[i].end());
        for (auto &e:res[i])
            cout<<e<<"\n";
    }
    return 0;
}



