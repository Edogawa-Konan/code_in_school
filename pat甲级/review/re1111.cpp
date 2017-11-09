//
// @author prime on 2017/9/16.
//

#include <iostream>
#include <vector>

using namespace std;

const int inf=99999999;
int G[500][500];
int T[500][500];
vector<int> dist(500,inf),ttime(500,inf),dist_time(500,inf);
vector<int> dis_pre(500),time_pre[500];
vector<int> dis_path,time_path,tmp_path;
bool visited[500];
int start,destination;

void DFS_dist(int u)
{
    tmp_path.push_back(u);
    if(u==start)
    {
        dis_path=tmp_path;
    }
    else
    {
        DFS_dist(dis_pre[u]);
    }
    tmp_path.pop_back();
}

int min_intersection=inf;
void DFS_time(int u)
{
    tmp_path.push_back(u);
    if(u==start)
    {
        if(tmp_path.size()<min_intersection)
        {
            min_intersection=tmp_path.size();
            time_path=tmp_path;
        }
    } else
    {
        for (auto&e:time_pre[u])
            DFS_time(e);
    }
    tmp_path.pop_back();
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    fill(G[0],G[0]+500*500,inf);
    fill(T[0],T[0]+500*500,inf);
    fill(dist.begin(),dist.end(),inf);
    for (int i=0;i<M;++i)
    {
        int u,v,one,length,ttime;
        scanf("%d %d %d %d %d",&u,&v,&one,&length,&ttime);
        G[u][v]=length;
        T[u][v]=ttime;
        if(one==0)
        {
            G[v][u]=length;
            T[v][u]=ttime;
        }
    }

    scanf("%d %d",&start,&destination);

    dist[start]=0;
    dist_time[start]=0;
    ttime[start]=0;

    for (int i=0;i<N;++i)
        dis_pre[i]=i;

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
                if(dist[u]+G[u][v]<dist[v])
                {
                    dist[v]=dist[u]+G[u][v];
                    dis_pre[v]=u;
                    dist_time[v]=dist_time[u]+T[u][v];
                }
                else if(dist[u]+G[u][v]==dist[v]&&dist_time[v]>dist_time[u]+T[u][v])
                {//dist_time用于统计到某个地点的时间，和dist类似。
                    dist_time[v]=dist_time[u]+T[u][v];
                    dis_pre[v]=u;
                }
            }
        }
    }
    DFS_dist(destination);

    fill(visited,visited+500, false);
    tmp_path.clear();
    for (int i=0;i<N;++i)
    {
        int min_time=inf,u=-1;
        for (int j=1;j<N;++j)
        {
            if(!visited[j]&&ttime[j]<min_time)
            {
                min_time=ttime[j];
                u=j;
            }
        }
        if(u==-1)
            break;
        visited[u]=true;
        for (int v=0;v<N;++v)
        {
            if(!visited[v]&&T[u][v]!=inf)
            {
                if(ttime[u]+T[u][v]<ttime[v])
                {
                    ttime[v]=ttime[u]+T[u][v];
                    time_pre[v].clear();
                    time_pre[v].push_back(u);
                } else if(ttime[u]+T[u][v]==ttime[v])
                {
                    time_pre[v].push_back(u);
                }
            }

        }
    }
    DFS_time(destination);
    if(dis_path==time_path)
    {
        printf("Distance = %d; Time = %d: ",dist[destination],ttime[destination]);
        for (int i=dis_path.size()-1;i>=0;i--)
        {
            printf("%d",dis_path[i]);
            if(i!=0)
                printf(" -> ");
        }
    } else
    {
        printf("Distance = %d: ",dist[destination]);
        for (int i=dis_path.size()-1;i>=0;i--)
        {
            printf("%d",dis_path[i]);
            if(i!=0)
                printf(" -> ");
        }
        printf("\nTime = %d: ",ttime[destination]);
        for (int i=time_path.size()-1;i>=0;i--)
        {
            printf("%d",time_path[i]);
            if(i!=0)
                printf(" -> ");
        }
    }
    return 0;
}

