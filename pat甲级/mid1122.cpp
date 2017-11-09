//
// @author prime on 2017/8/5.
//


#include <iostream>
#include <vector>


using namespace std;

const int inf=99999999;
int G[201][201];
int N,M,K;

bool isConnect(const vector<int>&s)
{//判断这条路是不是通的
    for (int i=1;i<s.size();++i)
    {
        if(G[s[i]][s[i-1]]!=1)
            return false;
    }
    return true;
}

bool isHamiltonian(const vector<int>&s)
{
    if(s.front()!=s.back())
        return false;
    vector<int> one(N+1,0);
    for (auto&e:s)
        one[e]++;
    for(int i=1;i<=N;++i)
    {
        if(one[i]!=1)
        {
            if(i==s.front()&&one[i]==2)
                continue;
            return false;
        }
    }
    return true;
}

int main()
{
    fill(G[0],G[0]+201*201,inf);
    scanf("%d%d",&N,&M);
    for (int i=0;i<M;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u][v]=G[v][u]=1;
    }
    scanf("%d",&K);
    for (int i=0;i<K;++i)
    {
        int num;
        scanf("%d",&num);
        vector<int> s(num);
        for (int j=0;j<num;j++)
            scanf("%d",&s[j]);
        if(isHamiltonian(s)&&isConnect(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
