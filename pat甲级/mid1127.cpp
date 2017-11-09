//
// @author prime on 2017/8/13.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> in,post,res[35];

int N,root,tree[35][2];//存储的都是后序中的下标

struct Node
{
    int index,depth;
};

void DFS(int &index,int in_begin,int in_end,int post_begin,int post_end)
{
    if(post_begin>post_end)
        return;
    index=post_end;//后序中的根下标
    int root;//中序遍历中的根下标
    for (root=in_begin;root<=in_end&&in[root]!=post[post_end];++root);

    DFS(tree[index][0],in_begin,root-1,post_begin,post_begin+(root-1-in_begin));
    DFS(tree[index][1],root+1,in_end,post_begin+root-in_begin,post_end-1);
//    DFS(tree[index][0],root+1,in_end,post_end-(in_end-root-1)-1,post_end-1);
}


int main()
{
    scanf("%d",&N);
    in.resize(N+1);
    post.resize(N+1);
    for (int i=1;i<=N;++i)//这里用下标1~N保存下标比较好，不然下面BFS里下标0不好区分是没孩子还是孩子是第一个。
        scanf("%d",&in[i]);
    for(int i=1;i<=N;++i)
        scanf("%d",&post[i]);
    DFS(root,1,N,1,N);
    deque<Node> queue;
    queue.push_back(Node{root,1});
    while (!queue.empty())
    {
        Node t=queue[0];
        queue.pop_front();
        res[t.depth].push_back(post[t.index]);
        if(tree[t.index][0]!=0)//用0作为孩子存在与否的判定
            queue.push_back(Node{tree[t.index][0],t.depth+1});
        if(tree[t.index][1]!=0)
            queue.push_back(Node{tree[t.index][1],t.depth+1});
    }
    printf("%d",res[1][0]);
    for (int i=2;i<35;i++)
    {
        if(i%2==1)
        {
            for(auto it=res[i].rbegin();it!=res[i].rend();it++)
                printf(" %d",*it);
        }
        else
        {
            for (auto &e:res[i])
                printf(" %d",e);
        }
    }
    return 0;
}




