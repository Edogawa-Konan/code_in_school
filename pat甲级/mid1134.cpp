//
// @author prime on 2017/10/7.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N,M,K;

bool check(vector<int> G[])
{
    int nv,id;
    scanf("%d",&nv);
    unordered_set<int> tmp;
    for (int j=0;j<nv;j++)
    {
        scanf("%d",&id);
        tmp.insert(id);
    }
    for (int j=0;j<N;++j)
    {
        if(tmp.find(j)==tmp.end())
        {
            for(auto&e:G[j])
            {
                if(tmp.find(e)==tmp.end())
                {
                    return false;
                }
            }
        }
    }
    return true;

}

int main()
{
    scanf("%d %d",&N,&M);
    vector<int> G[N];
    for(int i=0;i<M;++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    scanf("%d",&K);
    for (int i=0;i<K;++i)
    {
        if(check(G))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}



