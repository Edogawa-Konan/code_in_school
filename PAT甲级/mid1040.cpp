//
// @author prime on 2017/6/23.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string in;
    getline(cin,in);
    size_t len=in.size();
    int dp[len+1][len+1];
    fill(dp[0],dp[0]+(len+1)*(len+1), 0);
    string rev=in;
    reverse(rev.begin(),rev.end());
    int res=-1;
    for (int i=1;i<=len;++i)
    {
        for (int j=1;j<=len;++j)
        {
            if(in[j-1]==rev[i-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>res)
                {
                    res=dp[i][j];
                }
            }
            else
                dp[i][j]=0;
        }
    }
    cout<<res;
    return 0;
}


