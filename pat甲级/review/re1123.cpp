//
// @author prime on 2017/9/16.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node
{
    int val;
    Node *left,*right;
    Node()= default;
    Node(int v):val(v){this->left=this->right= nullptr;}
};

Node*Right_Rotation(Node*root)
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

Node* Left_Right_Rotation(Node*root)
{
    root->left=Left_Rotation(root->left);
    return Right_Rotation(root);
}

Node* Right_Left_Rotation(Node*root)
{
    root->right=Right_Rotation(root->right);
    return Left_Rotation(root);
}

int get_height(Node*root)
{
    if(root== nullptr)
        return 0;
    else
    {
        return max(get_height(root->left),get_height(root->right))+1;
    }
}

Node*insert(Node*root,int val)
{
    if(root== nullptr)
    {
        root=new Node(val);
    } else if(val<root->val)
    {
        root->left=insert(root->left,val);
        if(get_height(root->left)-get_height(root->right)==2)
        {
            root=val<root->left->val?Right_Rotation(root):Left_Right_Rotation(root);
        }
    } else
    {
        root->right=insert(root->right,val);
        if(get_height(root->right)-get_height(root->left)==2)
        {
            root=val<root->right->val?Right_Left_Rotation(root):Left_Rotation(root);
        }
    }
    return root;
}


int main()
{
    int N;
    scanf("%d",&N);
    int val;
    Node*root= nullptr;
    for (int i=0;i<N;++i)
    {
        scanf("%d",&val);
        root=insert(root,val);
    }
    deque<Node*> q;
    q.push_back(root);
    int count=0;
    bool is_complete=true,first=true;
    while(!q.empty())
    {
        Node*t=q[0];
        q.pop_front();
        if(t== nullptr&&first)
        {
            if(count==N)
                is_complete=true;
            else
                is_complete=false;
            first=false;
        }
        else if(t!= nullptr)
        {
            printf("%d",t->val);
            count++;
            if(count!=N)
                printf(" ");
            q.push_back(t->left);
            q.push_back(t->right);
        }
    }
    printf(is_complete?"\nYES":"\nNO");
    return 0;
}



