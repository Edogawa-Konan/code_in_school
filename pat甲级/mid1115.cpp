//
// @author prime on 2017/8/4.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node*left,*right;
    Node()= default;
    Node(int v):val(v)
    {
        this->left=this->right= nullptr;
    }
};

Node* insert(Node*root,int v)
{
    if(root== nullptr)
        root=new Node(v);
    else if(v<=root->val)
        root->left=insert(root->left,v);
    else
        root->right=insert(root->right,v);
    return root;
}

int max_depth=-1;
vector<int> level(1001);//下标记录哪一层的结点数目

void DFS(const Node*root,int depth)
{
    if(root== nullptr)
    {
        max_depth=depth-1>max_depth?depth-1:max_depth;//之所以减一因为这里没有结点，所以depth+1要去掉
        return;
    }
    level[depth]++;
    DFS(root->left,depth+1);
    DFS(root->right,depth+1);
}



int main()
{
    int N;
    scanf("%d",&N);
    Node*root= nullptr;
    for (int i=0,val;i<N;++i)
    {
        scanf("%d",&val);
        root=insert(root,val);
    }
    DFS(root,1);
    printf("%d + %d = %d",level[max_depth],level[max_depth-1],level[max_depth]+level[max_depth-1]);
    return 0;
}
