//
// @author prime on 2017/6/9.
//
#include <iostream>
#include <algorithm>

using namespace std;




int main()
{
    int N,M,C1,C2;
    cin>>N>>M>>C1>>C2;

    const int inf=99999999;
    int G[N][N];
    int rescue[N];
    int dist[N];
    bool visited[N];
    int path_count[N];//到每个结点的最短路径条数
    int rescue_total[N];//到每个结点的救援队总数

    fill(visited,visited+N, false);
    fill(G[0],G[0]+N*N,inf);
    fill(dist,dist+N,inf);

    for (int i=0;i<N;i++)
    {
        cin>>rescue[i];
    }
    for (int i=0,u,v;i<M;++i)
    {
        cin>>u>>v;
        cin>>G[u][v];
        G[v][u]=G[u][v];
    }

    dist[C1]=0;
    rescue_total[C1]=rescue[C1];
    path_count[C1]=1;

    for (int i=0;i<N;++i)
    {
        int min_d=inf,u=-1;
        for (int j=0;j<N;++j)
        {
            if(!visited[j]&&dist[j]<min_d)
            {
                min_d=dist[j];
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

                    path_count[v]=path_count[u];
                    rescue_total[v]=rescue[v]+rescue_total[u];
                }
                else if(G[u][v]+dist[u]==dist[v])
                {
                    if(rescue[v]+rescue_total[u]>rescue_total[v])
                    {
                        rescue_total[v]=rescue[v]+rescue_total[u];
                    }
                    path_count[v]=path_count[u]+path_count[v];
                }
            }
        }
    }
    /*debug*/
    /*cout<<"------------------"<<endl;
    for(int i=0;i<N;++i)
        cout<<dist[i]<<" ";
    cout<<endl;*/
    /*for (int i=0;i<N;++i)
        cout<<rescue_total[i]<<" ";
    cout<<endl;*/

    cout<<path_count[C2]<<" "<<rescue_total[C2];
    return 0;
}



