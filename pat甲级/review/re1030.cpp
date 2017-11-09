//
// @author prime on 2017/9/12.
//

#include <iostream>
#include <vector>

using namespace std;

int G[500][500];
int cost[500][500];
int dist[500];
const int inf=9999999;
bool visited[500];
vector<int> pre[500];
vector<int> tmp_path,path;
int min_cost=inf;
int N,M,S,D;

void DFS(int u)
{
    tmp_path.push_back(u);
    if(u==S)
    {
        int tmp_cost=0;
        for (int i=tmp_path.size()-1;i>0;i--)
        {
            tmp_cost+=cost[tmp_path[i-1]][tmp_path[i]];
        }
        if(tmp_cost<min_cost)
        {
            path=tmp_path;
            min_cost=tmp_cost;
        }
    } else
    {
        for (auto&e:pre[u])
            DFS(e);
    }
    tmp_path.pop_back();
}

int main()
{
    fill(G[0],G[0]+500*500,inf);
    fill(cost[0],cost[0]+500*500,inf);
    scanf("%d %d %d %d",&N,&M,&S,&D);
    for (int i=0;i<M;++i)
    {
        int u,v,dis,cos;
        scanf("%d%d%d%d",&u,&v,&dis,&cos);
        G[u][v]=dis;
        G[v][u]=dis;
        cost[u][v]=cos;
        cost[v][u]=cos;
    }
    fill(dist,dist+500,inf);
    dist[S]=0;

    for (int i=0;i<N;++i)
    {
        int min_dist=inf,u=-1;
        for (int j=0;j<N;++j)
        {
            if(!visited[j]&&dist[j]<min_dist)
            {
                min_dist=dist[j];
                u=j;
            }
        }
        if(u==-1)
            break;
        visited[u]=true;

        for (int v=0;v<N;++v)
        {
            if(!visited[v]&&G[u][v]!=inf)
            {
                if(G[u][v]+dist[u]<dist[v])
                {
                    dist[v]=G[u][v]+dist[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(G[u][v]+dist[u]==dist[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
    DFS(D);
    for (int i=path.size()-1;i>=0;i--)
    {
        printf("%d",path[i]);
        if(i!=0)
            printf(" ");
    }
    printf(" %d %d",dist[D],min_cost);
    return 0;
}


