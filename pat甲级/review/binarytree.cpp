//
// @author prime on 2017/6/13.
//

#include <iostream>
#include <deque>
#include <map>

using namespace std;


struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int c)
    {
        this->val=c;
        left=right= nullptr;
    }
};

void preorder(Node* root)
{
    if(root!= nullptr)
    {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

void postorder(Node*root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}
void preorder2(Node* root)
{

    Node *T=root;
    deque<Node> stack;
    while(T||!stack.empty())
    {
        while(T)
        {//左子树全部进栈
            stack.push_back(*T);
            cout<<T->val<<" ";
            T=T->left;
        }
        if(!stack.empty())
        {
            T=&stack.back();//不能用*T=stack.back
            stack.pop_back();//访问栈顶，然后转向右子树。
            T=T->right;
        }
    }
}

void preorder3(Node*root)
{
    if(root== nullptr)
        return;
    deque<Node> stack;
    stack.push_back(*root);
    while(!stack.empty())
    {
        Node t=stack.back();
        cout<<t.val<<" ";
        stack.pop_back();
        if(t.right)
            stack.push_back(*t.right);
        if(t.left)
            stack.push_back(*t.left);
        /*先右孩子进栈，再左孩子进栈，才能满足先序。*/
    }
}

void inorder2(Node* root)
{

    Node *T=root;
    deque<Node> stack;
    while(T||!stack.empty())
    {
        while(T)
        {//左子树全部进栈
            stack.push_back(*T);
            T=T->left;
        }
        if(!stack.empty())
        {
            T=&stack.back();//不能用*T=stack.back
            stack.pop_back();//访问栈顶，然后转向右子树。
            cout<<T->val<<" ";
            T=T->right;
        }
    }
}

void postorder2(Node* root)
{
    if(root== nullptr)
        return;
    deque<Node> s1,s2;
    s1.push_back(*root);
    while(!s1.empty())
    {
        Node tmp=s1.back();
        s1.pop_back();
        if(tmp.left)
            s1.push_back(*tmp.left);
        if(tmp.right)
            s1.push_back(*tmp.right);
        s2.push_back(tmp);
    }
    while(!s2.empty())
    {
        cout<<s2.back().val<<" ";
        s2.pop_back();
    }
}

void postorder3(Node*root)
{
    if(root== nullptr)
        return;
    deque<Node*> stack;
    stack.push_back(root);
    Node *c;
    Node *h= nullptr;
    while (!stack.empty())
    {
        c=stack.back();
        if((c->left== nullptr&&c->right== nullptr)||(h&&(h==c->left||h==c->right)))
        {
            cout<<c->val<<" ";
            stack.pop_back();
            h=c;
        } else
        {
            if(c->right)
                stack.push_back(c->right);
            if(c->left)
                stack.push_back(c->left);
        }
    }
}

void postorder4(Node*root)
{
    if(root== nullptr)
        return;
    deque<Node*> stack;
    Node* pre= nullptr,*current=root;
    while (current||!stack.empty())
    {
        while (current!= nullptr)
        {//左孩子递归入栈
            stack.push_back(current);
            current=current->left;
        }
        current=stack.back();
        if(current->right== nullptr||current->right==pre)
        {//右子树为空或者已被访问
            cout<<current->val<<" ";
            pre=current;
            stack.pop_back();
            current= nullptr;//这个不能省。不然叶子结点无限重复。
        }
        else//否则进入右子树
            current=current->right;
    }
}

void printleaves(Node* root)
{
    if(root)
    {
        if(!root->left&&!root->right)
            cout<<root->val<<" ";
        printleaves(root->left);
        printleaves(root->right);
    }
}

int count_node(Node*root)
{
    if(root== nullptr)
        return 0;
    return 1+count_node(root->left)+count_node(root->right);
}

int getheight(Node* root)
{
    int L,R,H;
    if(root)
    {
        L=getheight(root->left);
        R=getheight(root->right);
        H=L>R?L:R;
        return H+1;
    } else
        return 0;
}

Node* pre_in(int* pre,int pre_i,int pre_j,int * in,int in_i,int in_j,map<int,int> &m)
{
    if(pre_i>pre_j)
        return nullptr;
    Node *head=new Node(pre[pre_i]);
    int index=m[pre[pre_i]];//左子树有index-in_i个结点
    head->left=pre_in(pre,pre_i+1,pre_i+index-in_i,in,in_i,index-1,m);
    head->right=pre_in(pre,pre_i+index-in_i+1,pre_j,in,index+1,in_j,m);
    return head;
}

Node* post_in(int* post,int post_i,int post_j,int *in,int in_i,int in_j,map<int,int>& m)
{
    if(post_i>post_j)
        return nullptr;
    Node* head=new Node(post[post_j]);
    int index=m[post[post_j]];//左子树依旧有index-in_i个结点
    head->left=post_in(post,post_i,post_i+index-in_i-1,in,in_i,index-1,m);
    head->right=post_in(post,post_i+index-in_i,post_j-1,in,index+1,in_j,m);
    return head;
}

int main()
{
    Node *root=new Node(1);
    root->left=new Node(5);
    root->left->left=new Node(7);
    root->right=new Node(8);

    int pre[4]={1,5,7,8};
    int in[4]={7,5,1,8};
    int post[4]={7,5,8,1};

    map<int,int> m;
    for (int i=0;i<4;++i)
        m[in[i]]=i;

    //Node *p=pre_in(pre,0,3,in,0,3,m);
    //Node *p=post_in(post,0,3,in,0,3,m);
    //preorder2(root);
    cout<<endl;
    //postorder(root);
    cout<<count_node(root);
    //cout<<getheight(root);
    //inorder2(root);
    cout<<endl;
    //postorder(root);

    return 0;
}


