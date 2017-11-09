//
// @author prime on 2017/7/1.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int inf=99999999;

int G[1020][1020];
bool visited[1020];
int dis[1020];

int main()
{
    int N,M,K,Ds;
    scanf("%d%d%d%d",&N,&M,&K,&Ds);
    fill(G[0],G[0]+1020*1020,inf);
    for (int i=0;i<K;++i)
    {//加油站编号为[N+1,
        int u,v,d;
        string tmp_u,tmp_v;
        cin>>tmp_u>>tmp_v>>d;
        if(tmp_u[0]=='G')
        {
            u=stoi(tmp_u.substr(1))+N;
        } else
            u=stoi(tmp_u);
        if(tmp_v[0]=='G')
            v=stoi(tmp_v.substr(1))+N;
        else
            v=stoi(tmp_v);
        G[u][v]=d;
        G[v][u]=d;
    }
    int res_id=-1;
    double res_dis=inf,min_dis=-1;//平均距离,离居民的最近距离
    for (int index=N+1;index<=N+M;++index)
    {//对每个加油站求其到任意居民楼的最短距离
        fill(visited,visited+1020, false);
        fill(dis,dis+1020,inf);
        dis[index]=0;
        for (int i=1;i<=N+M;++i)
        {//松弛N+M轮
            int u=-1,min_d=inf;
            for (int j=1;j<=N+M;j++)
            {
                if(dis[j]<min_d&&!visited[j])
                {
                    u=j;
                    min_d=dis[j];
                }
            }
            if(u==-1)
                break;
            visited[u]=true;
            for (int v=1;v<=N+M;v++)
            {
                if(!visited[v]&&G[u][v]!=inf)
                {
                    if(G[u][v]+dis[u]<dis[v])
                        dis[v]=G[u][v]+dis[u];
                }
            }
        }
        double tmp_dis=0,tmp_min=inf;//到所有居民的平均距离,最近距离
        bool valid=true;
        for (int i=1;i<=N;++i)
        {
            tmp_dis+=dis[i];
            if(dis[i]>Ds)
            {
                valid=false;
                break;
            }
            if(dis[i]<tmp_min)
            {
                tmp_min=dis[i];
            }
        }
        if(valid)
        {//这个加油站位置距离可以服务全部居民
            tmp_dis/=N;
            if(tmp_min>min_dis)//优先找离居民的最短距离最大的
            {
                res_dis=tmp_dis;
                res_id=index-N;
                min_dis=tmp_min;
            }
            else if(tmp_min==min_dis&&tmp_dis<res_dis)//次之找平均距离最短的
            {
                res_id=index-N;
                res_dis=tmp_dis;
            }
        }
    }
    if(res_id==-1)
    {
        printf("No Solution");
        return 0;
    }
    printf("G%d\n",res_id);
    printf("%.1lf %.1lf",min_dis,res_dis);
    return 0;
}



