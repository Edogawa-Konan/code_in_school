//
// @author prime on 2017/6/4.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int k1,k2;
    scanf("%d",&k1);
    float ans[2001],input[1001];
    int exponent;
    float coefficient;
    int total=0;
    memset(ans,0, sizeof(ans));
    memset(input,0, sizeof(input));
    for (int i=0;i<k1;++i)
    {
        scanf("%d %f",&exponent,&coefficient);
        input[exponent]=coefficient;
    }
    scanf("%d",&k2);
    for (int i=0;i<k2;++i)
    {
        scanf("%d %f",&exponent,&coefficient);
        if(coefficient!=0)
        {
            for(int j=0;j<=1000;j++)
            {
                ans[j+exponent]+=input[j]*coefficient;
            }
        }
    }
    for(int i=0;i<=2000;i++)
    {
        if(ans[i]!=0)
            total++;
    }
    printf("%d",total);
    for (int i=2000;i>=0;--i)
    {
        if(total==0)
            break;
        if(ans[i]!=0)
        {
            printf(" %d %.1f",i,ans[i]);
            total--;
        }
    }
}



