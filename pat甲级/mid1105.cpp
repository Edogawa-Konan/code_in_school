//
// @author prime on 2017/7/29.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int m,n;
    for (int i=sqrt(N);i>=1;i--)
    {
        if(N%i==0)
        {
            n=i;
            break;
        }
    }
    m=N/n;
    vector<int> s(N);
    for (int i=0;i<N;++i)
        scanf("%d",&s[i]);
    sort(s.begin(),s.end(),greater<int>());
    vector<vector<int>> res(m,vector<int>(n));//m*n矩阵
    int level=m/2+m%2;//一共有几圈
    int t=0;
    for (int i=0;i<level;i++)
    {
        for (int j=i;j<=n-1-i&&t<N;j++)
            res[i][j]=s[t++];
        for (int j=i+1;j<=m-1-i-1&&t<N;j++)
            res[j][n-i-1]=s[t++];
        for (int j=n-1-i;j>=i&&t<N;j--)
            res[m-1-i][j]=s[t++];
        for (int j=m-1-i-1;j>=i+1&&t<N;j--)
            res[j][i]=s[t++];
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d",res[i][j]);
            if(j!=n-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}


