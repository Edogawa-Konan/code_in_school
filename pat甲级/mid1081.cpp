//
// @author prime on 2017/7/6.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

long long gcd(long long a,long long b)
{//求最大公约数，可能为负，需要绝对值
    return b==0?abs(a):gcd(b,a%b);
}

int main()
{
    int N;
    scanf("%d",&N);
    long long a,b,res_a=0,res_b=1,gc;
    for(int i=0;i<N;++i)
    {
        scanf("%lld/%lld",&a,&b);
        gc=gcd(a,b);
        a/=gc;
        b/=gc;
        res_a=res_b*a+res_a*b;
        res_b=res_b*b;
        gc=gcd(res_a,res_b);
        res_a/=gc;
        res_b/=gc;
    }
    long long in=res_a/res_b;
    res_a-=in*res_b;
    if(in==0)
    {
        if(res_a==0)
            printf("0");
        else
            printf("%lld/%lld",res_a,res_b);
    }
    else
    {
        if(res_a==0)
            printf("%lld",in);
        else
            printf("%lld %lld/%lld",in,res_a,res_b);
    }
    return 0;
}
