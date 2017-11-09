//
// @author prime on 2017/6/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tree[20000];

void pre_traversal(const vector<int>& in_order,int start,int end,int index)
{
    if(start>end)
        return;
    int n = end - start + 1;//这棵子树一共n个结点
    int L=log(n)/log(2);//除去叶子层，一共有几层
    int num=n-(pow(2,L)-1);//叶子结点个数
    int root=start+(pow(2,L-1)-1)+min((double)num,pow(2,L-1));//根的左子树的最后一层可能满了也可能没满，所以需要用min确定到底有几个结点
    tree[index]=in_order[root];
    pre_traversal(in_order,start,root-1,2*index);
    pre_traversal(in_order,root+1,end,2*index+1);
}


int main()
{
    int N;
    scanf("%d",&N);
    fill(tree,tree+20000,-1);
    vector<int> in_order(N);
    for (int i=0;i<N;++i)
        scanf("%d",&in_order[i]);
    sort(in_order.begin(),in_order.end());
    pre_traversal(in_order,0,N-1,1);
    int count=0;
    for (auto&e:tree)
    {
        if(e!=-1)
        {
            if(count==N-1)
                printf("%d",e);
            else
                printf("%d ",e);
            count++;
        }
        if(count==N)
            break;
    }
    return 0;
}


