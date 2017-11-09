//
// @author prime on 2017/8/13.
//

#include <iostream>
#include <vector>

using namespace std;

bool judge(vector<int> &s)
{
    for (int i=2;i<s.size();++i)
    {
        for (int j=1;j<i;++j)
        {
            if(s[j]==s[i]||abs(s[j]-s[i])==abs(j-i))
                return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin>>N;
    for (int i=0;i<N;++i)
    {
        int K;
        scanf("%d",&K);
        vector<int> s(K+1);
        for (int j=1;j<=K;++j)
            scanf("%d",&s[j]);
        if(judge(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}



