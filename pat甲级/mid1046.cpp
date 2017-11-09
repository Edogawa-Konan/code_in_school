//
// @author prime on 2017/6/25.
//

#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int N,M;
    int total=0;
    scanf("%d",&N);
    vector<int> G(N+1);
    int dist[N+1];//dist[i]表示沿着编号顺序，从1到i的下一个结点的距离
    fill(dist,dist+N+1,0);
    for (int i=1;i<=N;++i)
    {
        scanf("%d",&G[i]);
        total+=G[i];
        dist[i]=total;
    }
    scanf("%d",&M);
    int pre,back,res;
    for (int i=0;i<M;++i)
    {
        scanf("%d%d",&pre,&back);
        if(back>pre)
            swap(pre,back);
        res=min(dist[pre-1]-dist[back-1],total-(dist[pre-1]-dist[back-1]));
        printf("%d\n",res);
    }
    return 0;
}


