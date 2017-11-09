//
// @author prime on 2017/7/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    vector<int> w(N);
    for (int i=0;i<N;++i)
        scanf("%d",&w[i]);
    int dp[N+1][M+1];//dp[i][j]从前i个商品中总重量不超过j的最大价值
    bool choice[N+1][M+1];//记录选择
    fill(choice[0],choice[0]+(N+1)*(M+1), false);
    fill(dp[0],dp[0]+M+1,0);
    sort(w.begin(),w.end(),greater<int>());
    for (int i=0;i<N;++i)
        for (int j=0;j<=M;j++)
        {
            if(j<w[i])
                dp[i+1][j]=dp[i][j];
            else
            {
                if(dp[i][j]>dp[i][j-w[i]]+w[i])
                {
                    dp[i+1][j]=dp[i][j];
                }
                else
                {
                    dp[i+1][j]=dp[i][j-w[i]]+w[i];
                    choice[i][j]=true;
                }
            }
        }
    if(dp[N][M]!=M)
        printf("No Solution");
    else
    {
        vector<int> res;
        int total=M,index=N;
        while(total!=0)
        {
            if(choice[index][total])
            {
                res.push_back(w[index]);
                total-=w[index];
            }
            index--;
        }
        for (int i=0;i<res.size();++i)
        {
            printf("%d",res[i]);
            if(i!=res.size()-1)
                printf(" ");
        }
    }
    return 0;
}

