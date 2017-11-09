//
// @author prime on 2017/7/26.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> tree[100];

struct Node
{
    int id;
    int level;
    Node(int i,int l):id(i),level(l){};
};

int level,population=0;

void BFS(int u)
{
    deque<Node> queue;
    queue.push_back(Node(u,1));
    int temp=0;
    int tmp_level=1;
    while(!queue.empty())
    {
        temp=0;
        while(queue[0].level==tmp_level)
        {
            Node node=queue[0];
            for (auto&e:tree[node.id])
                queue.push_back(Node(e,tmp_level+1));
            queue.pop_front();
            temp++;
        }
        if(temp>population)
        {
            population=temp;
            level=tmp_level;
        }
        tmp_level++;
    }
}



int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i)
    {
        int k,id,child;
        scanf("%d%d",&id,&k);
        for (int j=0;j<k;++j)
        {
            scanf("%d",&child);
            tree[id].push_back(child);
        }
    }
    BFS(1);
    printf("%d %d",population,level);
    return 0;
}




