//
// @author prime on 2017/8/4.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> pre,post,in;
bool unique=true;

int Find_Root(int v,int start,int end)
{
    for (int i=start;i<=end;++i)
        if(pre[i]==v)
            return i;
    return -1;
}

void inorder(int pre_b,int pre_e,int post_b,int post_e)
{
    if(pre_b==pre_e)
        in.push_back(pre[pre_b]);
    else if(pre[pre_b]==post[post_e])
    {
        int root=Find_Root(post[post_e-1],pre_b+1,pre_e);//根结点在先序中的下标
        if(root-pre_b>1)
        {
            inorder(pre_b+1,root-1,post_b,post_b+root-pre_b-2);//左子树
            in.push_back(post[post_e]);
            inorder(root,pre_e,post_e-(pre_e-root)-1,post_e-1);//右子树
        } else//左孩子还是右孩子不能确定
        {
            unique=false;
            in.push_back(post[post_e]);
            inorder(root,pre_e,post_e-(pre_e-root)-1,post_e-1);//默认归为右子树
        }
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    pre.resize(N),post.resize(N);
    for (int i=0;i<N;i++)
        scanf("%d",&pre[i]);
    for (int i=0;i<N;++i)
        scanf("%d",&post[i]);
    inorder(0,N-1,0,N-1);
    printf("%s\n",unique?"Yes":"No");
    for (int i=0;i<N;i++)
    {
        printf("%d",in[i]);
        if(i!=N-1)
            printf(" ");
    }
    printf("\n");
    return 0;
}



