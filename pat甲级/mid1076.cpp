//
// @author prime on 2017/7/3.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N,L;
vector <vector<int>> G;
bool visited[1005];

struct Node
{
    int id;
    int layer;//第几层
};

int BFS(int u)
{//返回总共转发的次数
    fill(visited,visited+1005, false);
    deque<Node> queue;
    //头结点入队列
    Node top;
    top.id=u;
    top.layer=0;
    queue.push_back(top);
    visited[u]=true;//visited保证每个元素只进一次队列
    int res=0;
    while(!queue.empty())
    {
        top=queue[0];
        queue.pop_front();

        for (int i=0;i<G[top.id].size();i++)
        {
            Node next;
            if(!visited[G[top.id][i]]&&top.layer<L)
            {
                next.id=G[top.id][i];
                next.layer=top.layer+1;
                queue.push_back(next);
                visited[G[top.id][i]]=true;
                res++;//不能再pop的时候统计，因为这样起点也算进来了，起点不算的。
            }
        }
    }
    return res;
}



int main()
{
    scanf("%d%d",&N,&L);
    G.resize(N+1);
    for (int i=1;i<=N;++i)
    {
        int k;
        scanf("%d",&k);
        for (int j=0;j<k;++j)
        {
            int id;
            scanf("%d",&id);
            G[id].push_back(i);
            /*注意不是G[i].push_back(id)，只有这样得到的G[id]才是每个id的follower*/
        }
    }
    int K;
    scanf("%d",&K);
    for (int i=0;i<K;++i)
    {
        int query;
        scanf("%d",&query);
        printf("%d\n",BFS(query));
    }
    return 0;
}

