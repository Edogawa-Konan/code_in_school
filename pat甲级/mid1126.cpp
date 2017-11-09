//
// @author prime on 2017/8/11.
//

#include <iostream>
#include <vector>

using namespace std;

int N,M;

vector<vector<int>> G(501);
bool visited[501];
int total=0;//统计DFS经历过得结点个数，等于N表示连通

bool IsConnect(int u)
{
    visited[u]=true;
    total++;
    for (auto &e:G[u])
    {
        if(!visited[e])
            IsConnect(e);
    }
}


int main()
{
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int even=0;
    for (int i=1;i<=N;++i)
    {
        printf("%d",G[i].size());
        if(i!=N)
            printf(" ");
        if(G[i].size()%2==0)
            even++;
    }
    IsConnect(1);
    printf("\n");
    if(total==N&&even==N)
        printf("Eulerian");
    else if(total==N&&even==N-2)
        printf("Semi-Eulerian");
    else
        printf("Non-Eulerian");
    return 0;
}

