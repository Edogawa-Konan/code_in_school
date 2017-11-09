//
// @author prime on 2017/7/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct Node
{
    int val;
    int left,right;
    Node()= default;
};

vector<Node> tree;
vector<int> v;

int point=0;

void in_order(int root)
{
    if(root==-1)
        return;
    in_order(tree[root].left);
    tree[root].val=v[point++];
    in_order(tree[root].right);
}


int main()
{
    int N;
    scanf("%d",&N);
    tree.resize(N);
    v.resize(N);
    for (int i=0;i<N;++i)
        scanf("%d%d",&tree[i].left,&tree[i].right);
    for (int i=0;i<N;++i)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    in_order(0);
    deque<Node> queue;
    queue.push_back(tree[0]);
    while(!queue.empty())
    {
        Node t=queue[0];
        printf("%d",t.val);
        if(t.left!=-1)
            queue.push_back(tree[t.left]);
        if(t.right!=-1)
            queue.push_back(tree[t.right]);
        queue.pop_front();
        if(!queue.empty())
            printf(" ");
    }
    return 0;
}


