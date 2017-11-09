//
// @author prime on 2017/7/24.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
using namespace std;

vector<int> pre,in,post;//先序、中序序列

void postorder(int root,int start,int end)
{
    if(start>end)
        return;
    int i;//代表中序的根节点下标
    for(i=start;i<=end;i++)
    {
        if(in[i]==pre[root])
            break;
    }
    postorder(root+1,start,i-1);
    postorder(root+(i-start)+1,i+1,end);
    post.push_back(pre[root]);
}


int main()
{
    int N;
    scanf("%d",&N);
    char op[5];
    deque<int> stack;
    for (int i=0;i<2*N;++i)
    {
        scanf("%s",op);
        int num;
        if(strlen(op)==4)
        {
            scanf("%d",&num);
            pre.push_back(num);
            stack.push_back(num);
        }
        else
        {
            num=stack.back();
            in.push_back(num);
            stack.pop_back();
        }
    }
    /*debug*/
//    for(auto &e:pre)
//        printf("%d ",e);
//    printf("\n");
//    for(auto &e:in)
//        printf("%d ",e);
    postorder(0,0,N-1);
    for(int i=0;i<post.size();++i)
    {
        printf("%d",post[i]);
        if(i!=post.size()-1)
            printf(" ");
    }
    return 0;
}

