//
// @author prime on 2017/6/17.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int G[2010][2010];
int weight[2010];
bool visited[2010];

map<string,int> si;//名字到编号的映射
map<int,string> is;
map<string,int> res;//老大和小弟数的键值对
int number=1;//顶点的个数

void DFS(int u,int &member,int &head,int &total)
{
    visited[u]=true;
    member++;
    if(weight[u]>weight[head])
        head=u;
    for (int v=1;v<=number;++v)
    {
        if(G[u][v]>0)
        {
            total+=G[u][v];
            G[u][v]=G[v][u]=0;//计算之后把边权置0，防止重复计算total
            if(!visited[v])
            {
                DFS(v,member,head,total);
            }
        }
    }
}

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    for (int i=0;i<N;++i)
    {
        string name1,name2;int time;
        cin>>name1>>name2>>time;
        if(si[name1]==0)
        {
            si[name1]=number;
            is[number]=name1;
            number++;
        }
        if(si[name2]==0)
        {
            si[name2]=number;
            is[number]=name2;
            number++;
        }
        G[si[name1]][si[name2]]+=time;
        G[si[name2]][si[name1]]+=time;
        weight[si[name1]]+=time;
        weight[si[name2]]+=time;
    }
    fill(visited,visited+2010,false);
    for (int u=1;u<=number;++u)
    {
        if(!visited[u])
        {
            int head=u,total=0,member=0;
            DFS(u,member,head,total);
            if(member>2&&total>K)
                res[is[head]]=member;
        }
    }
    cout<<res.size();
    for (auto &e:res)
    {
        cout<<"\n"<<e.first<<" "<<e.second;
    }
    return 0;
}



