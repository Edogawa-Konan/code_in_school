//
// @author prime on 2017/7/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct Node
{
    int left,right;
};

vector<Node> tree(10);

void BFS(int root)
{
    deque<int> queue;
    queue.push_back(root);
    while(!queue.empty())
    {
        int t=queue[0];
        if(tree[t].left!=-1)
            queue.push_back(tree[t].left);
        if(tree[t].right!=-1)
            queue.push_back(tree[t].right);
        printf("%d",t);
        queue.pop_front();
        if(!queue.empty())
            printf(" ");
    }
}
int num;

void in_order(int root)
{
    if(root==-1)
        return;
    in_order(tree[root].left);
    printf("%d",root);
    num--;
    if(num!=0)
        printf(" ");
    in_order(tree[root].right);
}



int main()
{
    int N;
    scanf("%d",&N);
    num=N;
    bool exist[N];
    fill(exist,exist+N,false);
    for (int i=0;i<N;++i)
    {
        string L,R;
        cin>>L>>R;
        if(L=="-")
            tree[i].right=-1;
        else
        {
            tree[i].right=stoi(L);
            exist[tree[i].right]=true;
        }
        if(R=="-")
            tree[i].left=-1;
        else
        {
            tree[i].left=stoi(R);
            exist[tree[i].left]=true;
        }
    }
    int root;
    for (int i=0;i<N;++i)
    {
        if(!exist[i])
        {
            root=i;
            break;
        }
    }
    BFS(root);
    printf("\n");
    in_order(root);
    return 0;
}

