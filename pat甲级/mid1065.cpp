//
// @author prime on 2017/6/30.
//
#include <iostream>
using namespace std;




int main()
{
    int T;
    scanf("%d",&T);
    long long a,b,c,sum;
    for (int i=0;i<T;++i)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        sum=a+b;
        printf("Case #%d: ",i+1);
        if(a>0&&b>0)
        {
            if(sum>0&&sum<=c)
                printf("false\n");
            else
                printf("true\n");
        } else if(a<0&&b<0)
        {
            if(sum<0&&sum>c)
                printf("true\n");
            else
                printf("false\n");
        } else
        {
            if(sum<=c)
                printf("false\n");
            else
                printf("true\n");
        }
    }
    return 0;
}



