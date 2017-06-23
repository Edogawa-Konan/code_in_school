//
// @author prime on 2017/6/15.
//

#include <iostream>
#include <vector>

using namespace std;

const int inf=99999999;
int G[510][510];
int cost[510][510];
int dist[510];
bool visited[510];
int N,M,S,D;
vector<int> pre[510];
vector<int> path,tmp_path;

int min_cost=inf,tmp_cost;
void DFS(int u);


int main()
{
    /*初始化各种变量*/
    fill(visited,visited+510, false);
    fill(G[0],G[0]+510*510,inf);
    fill(dist,dist+510,inf);
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for (int i=0,u,v;i<M;++i)
    {
        scanf("%d %d",&u,&v);
        scanf("%d %d",&G[u][v],&cost[u][v]);
        G[v][u]=G[u][v];
        cost[v][u]=cost[u][v];
    }
    dist[S]=0;
    //pre[S].push_back(S);
    for (int i=0;i<N;++i)
    {
        int min_dist=inf,u=-1;
        for (int j=0;j<N;++j)
        {
            if(!visited[j]&&min_dist>dist[j])
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
                if(dist[v]>dist[u]+G[u][v])
                {
                    pre[v].clear();
                    pre[v].push_back(u);
                    dist[v]=dist[u]+G[u][v];
                } else if(dist[v]==dist[u]+G[u][v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
    //fill(visited,visited+N, false);
    DFS(D);
    for (int i=path.size()-1;i>=0;--i)
        printf("%d ",path[i]);
    printf("%d %d",dist[D],min_cost);
    return 0;
}

void DFS(int u)
{
    //visited[u]=true;
    if(u==S)
    {//从终点已经回到起点
        tmp_path.push_back(u);
        tmp_cost=0;
        for (int i=tmp_path.size()-1;i>0;i--)
        {//从源点到目的结点的路径
            int index=tmp_path[i];
            int next_index=tmp_path[i-1];
            tmp_cost+=cost[index][next_index];
        }
        if(tmp_cost<min_cost)
        {
            min_cost=tmp_cost;
            path=tmp_path;
        }
        tmp_path.pop_back();
    }
    else
    {
        tmp_path.push_back(u);
        for (int i=0;i<pre[u].size();i++)
        {
            DFS(pre[u][i]);
        }
        tmp_path.pop_back();
    }
}


