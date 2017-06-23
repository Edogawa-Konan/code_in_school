//
// @author prime on 2017/6/6.
//

#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int num)
{
    if(num<=1)
        return false;
    for (int i=2;i<=sqrt(num);++i)
    {
        if(num%i==0)
            return false;
    }
    return true;
}


int main()
{
    int n,radix,reverse=0,digit;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
            break;
        scanf("%d",&radix);
        if(!isprime(n))
        {
            printf("No\n");
            continue;
        }
        digit=log10(n)/log10(radix)+1;//这里不能用log10(n)，因为基数是radix，用换底公式解决吧！
        reverse=0;
        for (int i=digit-1;i>=0;--i)
        {
            reverse+=(int)pow((double)radix,(double)i)*(n%radix);
            n/=radix;
        }

       /*int arr[100];
        digit=-1;
        while (n!=0)
        {
            digit++;
            arr[digit]=n%radix;
            n/=radix;
        }
        reverse=0;
        for (int i=0;i<=digit;++i)
            reverse+=pow(radix,double(digit-i))*arr[i];*/
        //printf("reverse=:%d,digit=:%d\n",reverse,digit);
        /*int len = 0;
        int arr[100];
        do{
            arr[len++] = n % radix;
            n = n / radix;
        }while(n != 0);
        for(int i = 0; i < len; i++) {
            n = n * radix + arr[i];
        }*/
        if(isprime(reverse))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}



