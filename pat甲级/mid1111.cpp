//
// @author prime on 2017/8/3.
//

#include <iostream>
#include <vector>

using namespace std;

const int inf=99999999;
int D[500][500],T[500][500];
int dist[500],weight[500],Time[500];
bool visited[500];
vector<int> time_path,tmp_path,dist_path;
vector<int> timepre[500],dispre(500);
int source,destination;
int min_nodes=inf;

void DFS_T(int u)
{
    tmp_path.push_back(u);
    if(u==source)
    {
        if(tmp_path.size()<min_nodes)
        {
            time_path=tmp_path;
            min_nodes= tmp_path.size();
        }
    }
    else
    {
        for(auto &e:timepre[u])
            DFS_T(e);
    }
    tmp_path.pop_back();
}


void DFS_D(int u)
{
    tmp_path.push_back(u);
    if(u==source)
    {
        dist_path=tmp_path;
    } else
    {
        DFS_D(dispre[u]);
    }
    tmp_path.pop_back();
}


int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    fill(D[0],D[0]+500*500,inf);
    fill(T[0],T[0]+500*500,inf);
    fill(dist,dist+500, inf);
    fill(weight,weight+500,inf);
    fill(Time,Time+500,inf);
    fill(visited,visited+500, false);
    for (int i=0;i<M;i++)
    {
        int u,v,one,len,t;
        scanf("%d%d%d%d%d",&u,&v,&one,&len,&t);
        D[u][v]=len;
        T[u][v]=t;
        if(one!=1)
        {
            D[v][u]=len;
            T[v][u]=t;
        }
    }
    scanf("%d%d",&source,&destination);
    dist[source]=0;weight[source]=0;
    for (int i=0;i<N;i++)//一开始每个结点的前驱结点是自己
        dispre[i]=i;
    for (int i=0;i<N;++i)
    {
        int min_dist=inf,u=-1;
        for (int j=0;j<N;j++)
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
        for (int v=0;v<N;v++)
        {
            if(!visited[v]&&D[u][v]!=inf)
            {
                if(D[u][v]+dist[u]<dist[v])
                {
                    dist[v]=D[u][v]+dist[u];
                    weight[v]=T[u][v]+weight[u];
                    dispre[v]=u;
                } else if(D[u][v]+dist[u]==dist[v]&&weight[u]+T[u][v]<weight[v])
                {
                    weight[v]=T[u][v]+weight[u];
                    dispre[v]=u;
                }
            }
        }
    }
    DFS_D(destination);

    //*******************************************
    fill(visited,visited+500, false);
    Time[source]=0;
    for (int i=0;i<N;++i)
    {
        int min_time=inf,u=-1;
        for (int j=0;j<N;j++)
        {
            if(!visited[j]&&Time[j]<min_time)
            {
                min_time=Time[j];
                u=j;
            }
        }
        if(u==-1)
            break;
        visited[u]=true;
        for (int v=0;v<N;v++)
        {
            if(!visited[v]&&T[u][v]!=inf)
            {
                if(T[u][v]+Time[u]<Time[v])
                {
                    Time[v]=T[u][v]+Time[u];
                    timepre[v].clear();
                    timepre[v].push_back(u);
                } else if(T[u][v]+Time[u]==Time[v])
                {
                    timepre[v].push_back(u);
                }
            }
        }
    }
    DFS_T(destination);
    if(dist_path==time_path)
    {
        printf("Distance = %d; ",dist[destination]);
        printf("Time = %d: ",Time[destination]);
        for (int i=time_path.size()-1;i>=0;i--)
        {
            printf("%d",time_path[i]);
            if(i!=0)
                printf(" -> ");
        }
    }
    else
    {
        printf("Distance = %d: ",dist[destination]);
        for (int i=dist_path.size()-1;i>=0;i--)
        {
            printf("%d",dist_path[i]);
            if(i!=0)
                printf(" -> ");
        }
        printf("\n");
        printf("Time = %d: ",Time[destination]);
        for (int i=time_path.size()-1;i>=0;i--)
        {
            printf("%d",time_path[i]);
            if(i!=0)
                printf(" -> ");
        }
    }
    return 0;
}



