//
// @author prime on 2017/6/30.
//

#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left,*right;
};

Node* Right_Rotation(Node*root)
{
    Node*pivot=root->left;
    root->left=pivot->right;
    pivot->right=root;
    return pivot;
}

Node* Left_Rotation(Node*root)
{
    Node*pivot=root->right;
    root->right=pivot->left;
    pivot->left=root;
    return pivot;
}

Node* Left_Right_Rotation(Node* root)
{
    root->left=Left_Rotation(root->left);
    return Right_Rotation(root);
}

Node* Right_Left_Rotation(Node* root)
{
    root->right=Right_Rotation(root->right);
    return Left_Rotation(root);
}

int getHeight(Node*root)
{
    if(root== nullptr)
        return 0;
    else
        return max(getHeight(root->left),getHeight(root->right))+1;
}

Node* insert(Node*root,int val)
{
    if(root== nullptr)
    {
        root=new Node;
        root->val=val;
        root->left=root->right= nullptr;
    }
    else if(val<root->val)
    {//插入左子树
        root->left=insert(root->left,val);
        if(getHeight(root->left)-getHeight(root->right)==2)
            root=val<root->left->val?Right_Rotation(root):Left_Right_Rotation(root);
    }
    else
    {//插入右子树
        root->right=insert(root->right,val);
        if(getHeight(root->left)-getHeight(root->right)==-2)
            root=val<root->right->val?Right_Left_Rotation(root):Left_Rotation(root);
    }
    return root;
}


void pre_order(Node*root)
{
    if(root== nullptr)
        return;
    else
    {
        printf("%d ",root->val);
        pre_order(root->left);
        pre_order(root->right);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    Node* root= nullptr;
    for (int i=0;i<N;++i)
    {
        int val;
        scanf("%d",&val);
        root=insert(root,val);
    }
    //pre_order(root);
    printf("%d",root->val);
    return 0;
}
