//
// @author prime on 2017/9/16.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node*left,*right;
    Node()= default;
    Node(int v):val(v){this->left=this->right= nullptr;}
};

Node* insert(Node*root,int val)
{
    if(root== nullptr)
    {
        root=new Node(val);

    } else
    {
        if(val<=root->val)
            root->left=insert(root->left,val);
        else
            root->right=insert(root->right,val);
    }
    return root;
}

vector<int> level(1001,0);
int max_depth=-1;

void DFS(Node*root,int depth)
{
    if(root== nullptr)
    {
        if(depth-1>max_depth)
            max_depth=depth-1;
        return;
    }
    else
    {
        level[depth]++;
        DFS(root->left,depth+1);
        DFS(root->right,depth+1);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int v;
    Node*root= nullptr;
    for (int i=0;i<N;++i)
    {
        scanf("%d",&v);
        root=insert(root,v);
    }
    DFS(root,1);
    printf("%d + %d = %d",level[max_depth],level[max_depth-1],level[max_depth]+level[max_depth-1]);
    return 0;
}


