//
// @author prime on 2017/6/24.
//

#include <iostream>
using namespace std;

int favorite[201];
int res[10000];

int main()
{
    int N,M,L;
    scanf("%d%d",&N,&M);
    for (int i=1,x;i<=M;++i)
    {
        scanf("%d",&x);
        favorite[x]=i;//favorite数组建立了颜色到下标的映射。
    }
    scanf("%d",&L);
    int num=0;//去除不喜欢的颜色后还剩多少个。
    for (int i=0,x;i<L;++i)
    {
        scanf("%d",&x);
        if(favorite[x]>=1)//是喜爱的颜色
        {
            res[num++]=favorite[x];
        }
    }
    int dp[num];//dp[i]表示以i结尾的LIS长度
    fill(dp,dp+num,0);
    int max_length=0;//这里应该设置成0，如果所有的颜色都不是喜欢的，就应该是0。但是-1也过了~
    for (int i=0;i<num;i++)
    {
        dp[i]=1;
        for (int j=0;j<i;j++)
        {
            if(res[i]>=res[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        max_length=max(dp[i],max_length);
    }
    printf("%d",max_length);
    return 0;
}
