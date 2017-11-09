//
// @author prime on 2017/8/5.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


struct Node
{
    int val;
    Node*left,*right;
};

Node* Right_Rotation(Node*root)
{
    Node* pivot=root->left;
    root->left=pivot->right;
    pivot->right=root;
    return pivot;
}

Node* Left_Rotation(Node*root)
{
    Node* pivot=root->right;
    root->right=pivot->left;
    pivot->left=root;
    return pivot;
}

Node* Left_Right_Rotation(Node*root)
{
    root->left=Left_Rotation(root->left);
    return Right_Rotation(root);
}

Node* Right_Left_Rotation(Node* root)
{
    root->right=Right_Rotation(root->right);
    return Left_Rotation(root);
}

int Get_Height(Node*root)
{
    if(root== nullptr)
        return 0;
    else
        return max(Get_Height(root->left),Get_Height(root->right))+1;
}

Node* insert(Node*root, int val)
{
    if(root== nullptr)
    {
        root=new Node;
        root->left=root->right= nullptr;
        root->val=val;
    } else if(val<root->val)
    {
        root->left=insert(root->left,val);
        if(Get_Height(root->left)-Get_Height(root->right)>=2)
            root=val<root->left->val?Right_Rotation(root):Left_Right_Rotation(root);
    }
    else
    {
        root->right=insert(root->right,val);
        if(Get_Height(root->right)-Get_Height(root->left)>=2)
            root=val<root->right->val?Right_Left_Rotation(root):Left_Rotation(root);
    }
    return root;
}


int main()
{
    int N;
    scanf("%d",&N);
    Node*root= nullptr;
    for (int i=0;i<N;++i)
    {
        int v;
        scanf("%d",&v);
        root=insert(root,v);
    }
    bool isComplete=false,first=true;
    deque<Node*> queue;
    queue.push_back(root);
    int count=0;
    vector<int> res;
    while(!queue.empty())
    {
        Node*t=queue[0];
        queue.pop_front();
        if(t!= nullptr)
        {
            count++;
            queue.push_back(t->left);
            queue.push_back(t->right);
            res.push_back(t->val);
        }
        else
        {
            if(first&&count==N)
                isComplete=true;
            first=false;
        }
    }
    for (int i=0;i<res.size();i++)
    {
        printf("%d",res[i]);
        if(i!=res.size()-1)
            printf(" ");
    }
    if(isComplete)
        printf("\nYES");
    else
        printf("\nNO");
    return 0;
}

