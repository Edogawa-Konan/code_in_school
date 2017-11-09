//
// @author prime on 2017/7/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int G[201][201];//城市编号1~n
int weight[201];
int dist[201];
bool visited[201];
vector<int> pre[201];
const int inf=99999999;
unordered_map<string,int> s_i;
unordered_map<int,string> i_s;
vector<int> tmp_path,path;
int res_happiness=0; //总幸福值
double average=0;//平均幸福值，不算起点
int total_path=0;

//int path_count[201];

void DFS(int u)
{
    tmp_path.push_back(u);
    if(u==1)
    {
        int tmp_max_happiness=0;
        for (int i=0;i<tmp_path.size()-1;i++)
            tmp_max_happiness+=weight[tmp_path[i]];
        if(tmp_max_happiness>res_happiness)
        {
            res_happiness=tmp_max_happiness;
            average=res_happiness/(tmp_path.size()-1);
            path=tmp_path;
        }
        else if(tmp_max_happiness==res_happiness)
        {
            double tmp_average=tmp_max_happiness/(tmp_path.size()-1);
            if(tmp_average>average)
            {
                average=tmp_average;
                path=tmp_path;
            }
        }
        total_path++;//统计一共多少条最短路径
    }
    else
    {
        for(int i=0;i<pre[u].size();++i)
            DFS(pre[u][i]);
    }
    tmp_path.pop_back();
}


int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    fill(G[0],G[0]+201*201,inf);
    fill(dist,dist+201,inf);
    string name;
    cin>>name;
    s_i[name]=1;
    i_s[1]=name;
    dist[1]=0;//path_count[1]=1;
    for(int i=1;i<N;++i)
    {
        cin>>name>>weight[i+1];
        s_i[name]=i+1;
        i_s[i+1]=name;
    }
    for (int i=0;i<K;++i)
    {
        string u,v;
        int w;
        cin>>u>>v>>w;
        G[s_i[u]][s_i[v]]=w;
        G[s_i[v]][s_i[u]]=w;
    }

    for (int i=1;i<=N;++i)
    {
        int min_dist=inf,u=-1;
        for(int j=1;j<=N;++j)
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
        for (int v=1;v<=N;++v)
        {
            if(!visited[v]&&G[u][v]!=inf)
            {
                if(dist[u]+G[u][v]<dist[v])
                {
                    dist[v]=dist[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                    //path_count[v]=path_count[u];
                } else if(dist[u]+G[u][v]==dist[v])
                {
                    pre[v].push_back(u);
                    //path_count[v]+=path_count[u];
                }
            }
        }
    }
    DFS(s_i["ROM"]);
    printf("%d %d %d %.0f\n",total_path,dist[s_i["ROM"]],res_happiness,average);
    for(int i=path.size()-1;i>=0;i--)
    {
        cout<<i_s[path[i]];
        if(i!=0)
            printf("->");
    }
    return 0;
}

