//
// @author prime on 2017/6/28.
//


#include <iostream>
#include <vector>
using namespace std;

vector<bool> table(500000, true);

int main()
{
    for (int i=2;i*i<500000;i++)//埃氏筛选法——简化版
        for (int j=2;i*j<500000;j++)
            table[i*j]= false;
    long int a;
    scanf("%ld",&a);
    printf("%ld=",a);
    if(a==1)
    {
        printf("1");
    }
    bool first=true,valid;
    for (int i=2;a>=2;++i)
    {
        int exponent=0;valid= false;
        while(table[i]&&a%i==0)
        {
            exponent++;
            a/=i;
            valid=true;
        }
        /*if(first)
        {
            if(exponent==1)
            {
                printf("%d",i);
                first= false;
            }
            else if(exponent>=2)
            {
                printf("%d^%d",i,exponent);
                first= false;
            }
        }
        else
        {
            if(exponent==1)
            {
                printf("*%d",i);
            }
            else if(exponent>=2)
            {
                printf("*%d^%d",i,exponent);
            }
        }*/
        if(valid)//表示i是其中一项
        {
            if(first)//第一项特殊处理
            {
                printf("%d",i);
                first= false;
            }
            else
                printf("*%d",i);
        }
        if(exponent>=2)
            printf("^%d",exponent);
    }
    return 0;
}
