//
// @author prime on 2017/10/8.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node*left,*right;
    Node()= default;
    Node(int v):val(v) {left=right= nullptr;};
};

Node *insert(Node*root,int v)
{
    if(root== nullptr)
        root=new Node(v);
    else if(abs(v)<=abs(root->val))
        root->left=insert(root->left,v);
    else
        root->right=insert(root->right,v);
    return root;
}

bool is_red_black=false;
int num=-1;//辅助记忆黑色结点个数

void DFS(Node*root,int count)
{//count统计黑色结点个数
    if(!is_red_black) return;//为了排除下面的双红问题
    if(root== nullptr)
    {
        if(num==-1)
            num=count;//表示第一次初始化
        else if(num!=count)
            is_red_black=false;
        return;
    }
    if(root->val>0)
        count++;
    else
    {//当前root结点是红的，孩子不能是红色的了！
        if(root->left&&root->left->val<0)
            is_red_black=false;
        if(root->right&&root->right->val<0)
            is_red_black=false;
        //此处不可return！！！
    }
    DFS(root->left,count);
    DFS(root->right,count);

}

int main()
{
    int K;
    scanf("%d",&K);
    for (int i=0;i<K;++i)
    {
        int N;
        scanf("%d",&N);
        Node*root= nullptr;
        for (int j=0;j<N;++j)
        {
            int v;
            scanf("%d",&v);
            root=insert(root,v);
        }
        if(root->val<0)
        {
            printf("No\n");
            continue;
        }
        num=-1,is_red_black=true;
        DFS(root,0);
        if(is_red_black)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}



