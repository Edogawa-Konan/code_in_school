//
// @author prime on 2017/6/7.
//

#include <iostream>
#include <deque>

/*特殊用例 111*/
using namespace std;

struct Node
{
    int value;
    Node *left= nullptr;
    Node *right= nullptr;
    Node(int v)
    {
        value=v;
    }
};
Node *Build_tree(int *in_order,int *post_order,int length);

int main()
{
    int N;
    scanf("%d",&N);
    int post_order[N],in_order[N];
    for (int i=0;i<N;++i)
    {
        scanf("%d",&post_order[i]);
    }
    for (int i=0;i<N;++i)
        scanf("%d",&in_order[i]);
    Node *root=Build_tree(in_order,post_order,N);
    /*if(root)
        printf("%d",root->value);*/
    deque<Node> queue;
    Node *p=root;
    queue.push_back(*p);
    while(true)
    {

        *p=queue[0];
        if(p->left)
            queue.push_back(*p->left);
        if(p->right)
            queue.push_back(*p->right);
        if(queue.size()==1)
        {
            printf("%d",queue[0].value);
            return 0;
        }
        queue.pop_front();
        printf("%d ",p->value);
    }
}

Node *Build_tree(int in_order[],int post_order[],int length)//length代表中序序列长度
{
    if(length<=0)
    {
        return nullptr;
    }
    Node *root=new Node(post_order[length-1]);
    for(int i=0;i<length;++i)
    {
        if(in_order[i]==post_order[length-1])
        {
            int left_length=i,right_length=length-i-1;
            root->left=Build_tree(in_order,post_order,left_length);
            root->right=Build_tree(in_order+left_length+1,post_order+left_length,right_length);
            break;
        }
    }
    return root;
}

