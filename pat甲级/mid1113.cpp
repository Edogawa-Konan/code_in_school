//
// @author prime on 2017/8/3.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int> a(N);
    int sum1=0,sum2=0;
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    printf("%d",a.size()%2);
    for(int i=0;i<N;i++)
    {
        if(i<N/2)
            sum1+=a[i];
        sum2+=a[i];
    }
    printf(" %d",sum2-2*sum1);
    return 0;
}



