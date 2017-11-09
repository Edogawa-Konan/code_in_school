//
// @author prime on 2017/6/7.
//未通过

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int inf=99999999;

int G[510][510];
int dist[510];
bool visit[510];
vector<int> pre[510];
int current_capacity[510];
int min_take=inf,min_back=inf;
vector<int> path,tmp_path;
int C,N,Sp,M;

void DFS(int v);

int main()
{
    scanf("%d %d %d %d",&C,&N,&Sp,&M);
    fill(G[0],G[0]+(500+10)*(500+10),inf);
    fill(dist,dist+510,inf);
    fill(visit,visit+510, false);
    dist[0]=0;
    for (int i=1;i<=N;++i)
    {
        scanf("%d",&current_capacity[i]);
    }
    for (int i=0;i<M;++i)
    {
        int u,v,cost;
        scanf("%d %d %d",&u,&v,&cost);
        G[u][v]=cost;
        G[v][u]=cost;
    }
    /*dijkstra*/
    for(int i=0;i<=N;++i)
    {
        int min_dist=inf,u=-1;
        for (int j=0;j<=N;++j)
        {
            if(!visit[j]&&dist[j]<min_dist)
            {
                u=j;
                min_dist=dist[j];
            }
        }
        if(u==-1)
            break;
        visit[u]=true;

        for (int v=0;v<=N;++v)
        {
            if(!visit[v]&&G[u][v]!=inf)
            {
                if(dist[u]+G[u][v]<dist[v])
                {
                    dist[v]=dist[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);//记录前一个结点
                } else if(dist[u]+G[u][v]==dist[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
    DFS(Sp);//从终点倒着DFS
    printf("%d 0",min_take);
    for (int i=path.size()-2;i>=0;i--)
    {
        printf("->%d",path[i]);
    }
    printf(" %d",min_back);
    return 0;
}


void DFS(int v)
{//tmp_path[0]是终点，DFS的过程是从终点到起点。。
    tmp_path.push_back(v);
    if(v==0)
    {//从起点到终点进行统计
        int take=0,back=0;//带来几辆车，带回几辆车？
        for (int i=tmp_path.size()-2;i>=0;--i)
        {//从离起点最近的点开始
            int id=tmp_path[i];
            if(current_capacity[id]>C/2)
            {
                back+=(current_capacity[id]-C/2);
            }
            else if(current_capacity[id]<C/2)
            {
                int odd=C/2-current_capacity[id];//缺几辆车?
                if(back<odd)
                {
                    take+=odd-back;
                    back=0;
                } else
                {
                    back-=odd;
                }
            }
        }
        if(take<min_take)
        {
            min_take=take;
            min_back=back;
            path=tmp_path;
        } else if(min_take==take&&back<min_back)
        {
            min_back=back;
            path=tmp_path;
        }
    }
    else
    {
        for (int i=0;i<pre[v].size();++i)
        {
            DFS(pre[v][i]);//v的前驱结点全部递归
        }

    }
    tmp_path.pop_back();
}



