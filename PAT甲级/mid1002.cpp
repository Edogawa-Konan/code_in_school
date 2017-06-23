//
// @author prime on 2017/6/5.
//

#include <iostream>
#include <cstring>


using namespace std;

float input[1001];

int main()
{
    int k1,k2;
    float coefficient;
    int exponent;
    int total=0;
    memset(input,0, sizeof(input));
    scanf("%d",&k1);
    for (int i=0;i<k1;i++)
    {
        scanf("%d %f",&exponent,&coefficient);
        input[exponent]=coefficient;
    }
    scanf("%d",&k2);
    for (int i=0;i<k2;i++)
    {
        scanf("%d %f",&exponent,&coefficient);
        input[exponent]+=coefficient;
    }
    for (auto& e:input)
    {
        if(e!=0)
            total++;
    }
    printf("%d",total);
    for (int i=1000;i>=0;--i)
    {
        if(total==0)
            break;
        if(input[i]!=0)
        {
            printf(" %d %.1f",i,input[i]);
            total--;
        }
    }
    return 0;
}


