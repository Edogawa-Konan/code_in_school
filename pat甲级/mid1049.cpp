//
// @author prime on 2017/6/25.
//
#include <iostream>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int a=1,left,right,current;
    int ans=0;
    while(N/a)
    {
        left=N/(a*10);
        right=N%a;
        current=N/a%10;

        if(current==0)
        {
            ans+=left*a;//0~left-1共计left个情况
        }
        else if(current==1)
        {
            ans+=left*a+right+1;//0~right共计right+1个情况
        }
        else
            ans+=(left+1)*a;//0~left共计left+1个情况
        a*=10;
    }
    printf("%d",ans);
    return 0;
}


