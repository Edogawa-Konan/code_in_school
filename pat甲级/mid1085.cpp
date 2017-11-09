//
// @author prime on 2017/7/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    int N,p;
    scanf("%d%d",&N,&p);
    vector<long long> s(N);
    for (int i=0;i<N;++i)
    {
        scanf("%lld",&s[i]);
    }
    sort(s.begin(),s.end());
    int max=1;//如果不存在，显然应该输出1
//    for (int i=0;i<N;i++)
//        for (int j=N-1;j>i;j--)
//        {
//            if(s[i]*p>=s[j])
//            {
//                if(j-i+1>max)
//                    max=j-i+1;
//                break;
//            }
//        }
    for (int i=0;i<=N-2;++i)
        for(int j=i+max;j<N;++j)
        {
            if(s[i]*p>=s[j])
            {
                if(j-i+1>max)
                    max=j-i+1;
            } else
                break;
        }
    printf("%d",max);
    return 0;
}

