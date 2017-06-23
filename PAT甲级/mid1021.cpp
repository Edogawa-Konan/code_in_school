//
// @author prime on 2017/6/8.
//

#include <iostream>
#include <algorithm>
#include <set>


using namespace std;


int N;
vector<vector<int>> G;//邻接表。不能用邻接矩阵因为太大了超内存
vector<int> tmp;
set<int> res;
bool visited[10001];
int max_depth=-1;

void DFS(int u,int depth)
{
    visited[u]= true;
    if(depth>max_depth)
    {
        max_depth=depth;
        tmp.clear();
        tmp.push_back(u);
    } else if(depth==max_depth)
    {
        tmp.push_back(u);
    }
    for (int i=0;i<G[u].size();++i)
    {
        if(!visited[G[u][i]])
        {
            DFS(G[u][i],depth+1);
        }
    }


}

int main()
{

    fill(visited,visited+10001, false);
    scanf("%d",&N);
    G.resize(N+1);
    for (int i=0;i<N-1;++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cc=0;//连通分量个数
    int begin;//记录第一次DFS后tmp的第一个元素，后面以此为起点再次DFS。二次DFS并集就是所有的结果（一次可能会漏解）
    /*判断连通分量*/
    for (int i=1;i<=N;++i)
    {
        if(!visited[i])
        {
            DFS(i,1);
            cc++;
            if(i==1)
            {
                for (int j=0;j<tmp.size();++j)
                {
                    res.insert(tmp[j]);
                    if(j==0)
                        begin=tmp[j];
                }
            }
        }
    }
    /*debug*/
    /*for (set<int>::iterator it=res.begin();it!=res.end();it++)
        printf("%d ",*it);
    printf("\n");*/

    if(cc>1)
        printf("Error: %d components",cc);
    else
    {
        fill(visited,visited+N+1, false);
        tmp.clear();
        //max_depth=0;
        DFS(begin,1);
        for (int i=0;i<tmp.size();++i)
        {
            res.insert(tmp[i]);
        }
        for (set<int>::iterator it=res.begin();it!=res.end();it++)
            printf("%d\n",*it);
    }

    return 0;
}


