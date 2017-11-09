//
// @author prime on 2017/6/15.
//

#include <iostream>

using namespace std;

int post[] = {3, 4, 2, 6, 5, 1};
int in[] = {3, 2, 4, 1, 6, 5};
int pre[]={1,2,3,4,5,6};

void preorder(int root,int start,int end)
{//root是后序遍历的下标，代表根节点。start和end代表中序序列的边界。
    if(start>end)
        return;
    int i=start;
    while(i<end&&post[root]!=in[i])
        i++;//i是中序序列中根的下标
    cout<<in[i]<<" ";
    preorder(root-(end-i+1),start,i-1);
    preorder(root-1,i+1,end);
}

void postorder(int root,int start,int end)
{
    if(start>end)
        return;
    int i=start;
    while(i<end&&in[i]!=pre[root]) ++i;
    postorder(root+1,start,i-1);
    postorder(root+(i-start)+1,i+1,end);
    cout<<in[i]<<" ";
}


int main()
{
    //preorder(5,0,5);
    postorder(0,0,5);
    return 0;
}


