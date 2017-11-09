//
// @author prime on 2017/9/13.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> pre,post;

bool is_mirror=false;

void post_order(int begin,int end)
{
    if(begin>end)
    {
        return;
    }
    int i=begin+1,j=end;
    if(is_mirror)
    {
        for (;i<=end&&pre[i]<pre[begin];i++);
        for (;j>begin&&pre[j]>=pre[begin];j--);
    }
    else
    {
        for (;i<=end&&pre[i]>=pre[begin];i++);
        for (;j>begin&&pre[j]<pre[begin];j--);
    }
    /*if(i==j)
        return;*/
    post_order(begin+1,i-1);
    post_order(j+1,end);
    post.push_back(pre[begin]);

}

int main()
{
    int N;
    scanf("%d",&N);
    pre.resize(N+1);

    for (int i=1;i<=N;++i)
        scanf("%d",&pre[i]);

    post_order(1,N);
    if(post.size()!=N)
    {
        post.clear();
        is_mirror=true;
        post_order(1,N);
        if(post.size()!=N)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for (int i=0;i<N;++i)
    {
        printf("%d",post[i]);
        if(i!=N-1)
            printf(" ");
    }
    return 0;
}



