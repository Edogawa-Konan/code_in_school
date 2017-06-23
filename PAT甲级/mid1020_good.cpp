//
// @author prime on 2017/6/15.
//

#include <iostream>
#include <algorithm>

using namespace std;

int post[30];
int in[30];
int level[10000];

void pre_order(int root,int start,int end,int index)
{
    if(start>end)
        return;
    int i=start;
    while(i<end&&post[root]!=in[i]) i++;
    level[index]=post[root];
    pre_order(root-(end-i+1),start,i-1,2*index);
    pre_order(root-1,i+1,end,2*index+1);
}


int main()
{
    fill(level,level+10000,-1);
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;++i)
        scanf("%d",&post[i]);
    for (int i=0;i<N;++i)
        scanf("%d",&in[i]);
    pre_order(N-1,0,N-1,1);


    printf("%d",level[1]);
    int count=1;
    for (int i=2;i<10000;i++)
    {
        if(count==N)
            break;
        if(level[i]!=-1)
        {
            printf(" %d",level[i]);
            count++;
        }
    }
    return 0;
}


