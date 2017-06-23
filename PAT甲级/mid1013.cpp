//
// @author prime on 2017/6/6.
//

#include <iostream>
#include <algorithm>

using namespace std;

int G[1000][1000];
bool visited[1000];
int n;


void dfs(int source)
{
    visited[source]= true;
    for (int v=1;v<=n;++v)
    {
        if (!visited[v]&&G[source][v]==1)
        {
            dfs(v);
        }
    }
}

int main()
{
    int m,k;
    scanf("%d %d %d",&n,&m,&k);
    fill(visited,visited+n+1, false);
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u][v]=G[v][u]=1;
    }
    for (int i=0;i<k;++i)
    {
        int v,res=0;
        scanf("%d",&v);
        visited[v]= true;
        for (int j=1;j<=n;++j)
        {
            if(!visited[j])
            {
                dfs(j);
                res++;
            }
        }
        fill(visited,visited+n+1, false);
        printf("%d\n",res-1);
    }
    return 0;
}

