//
// @author prime on 2017/6/24.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;
vector<int> post;

bool ismirror=false;

void get_post(int root,int tail)
{//root和tail都是针对先序序列，root是先序第一个结点，tail是最后一个结点
    if(root>tail)
        return;
    int i=root+1,j=tail;//i，j用于确定左右子树。[root+1,i-1]是左子树，[j+1,tail]是右子树
    if(!ismirror)
    {//BST树
        for (;i<=tail&&pre[i]<pre[root];i++);
        for (;j>root&&pre[j]>=pre[root];j--);
    }
    else
    {//镜像BST树
        for (;i<=tail&&pre[i]>=pre[root];++i);
        for (;j>root&&pre[j]<pre[root];--j);
    }
    if(i==j)//没有交叉表明到了树的最底层
        return;
    get_post(root+1,i-1);
    get_post(j+1,tail);
    post.push_back(pre[root]);//左右根的顺序加入结果中
}

int main()
{
    int N;
    scanf("%d",&N);
    pre.resize(N);
    for (int i=0;i<N;++i)
        scanf("%d",&pre[i]);
    get_post(0,N-1);

    /*for (auto &e:post)
        printf("%d ",e);*/

    if(post.size()!=N)
    {
        post.clear();
        ismirror= true;
        get_post(0,N-1);
        if(post.size()!=N)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    printf("%d",post[0]);
    for(int i=1;i<N;++i)
        printf(" %d",post[i]);
    return 0;
}
