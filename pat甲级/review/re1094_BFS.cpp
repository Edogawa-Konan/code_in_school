//
// @author prime on 2017/9/15.
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
    Node()= default;
    Node(int i,int l):id(i),level(l){};
};

vector<int> generation(100);

void BFS()
{
    deque<Node> q;
    q.push_back(Node(1,1));
    while(!q.empty())
    {
        Node t=q[0];
        q.pop_front();
        for (auto&id:tree[t.id])
        {
            q.push_back(Node(id,t.level+1));
        }
        generation[t.level]++;
    }
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;++i)
    {
        int id,k,child;
        scanf("%d %d",&id,&k);
        for (int j=0;j<k;++j)
        {
            scanf("%d",&child);
            tree[id].push_back(child);
        }
    }
    BFS();
    int max_generation=-1,point=-1;
    for (int i=0;i<generation.size();++i)
    {
        if(generation[i]>max_generation)
        {
            max_generation=generation[i];
            point=i;
        }
    }
    printf("%d %d",max_generation,point);


    return 0;
}


