//
// @author prime on 2017/7/3.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isprime(int M)
{
    if(M<=1)
        return false;
    for(int i=2;i<=sqrt(M);i++)
    {
        if(M%i==0)
            return false;
    }
    return true;
}

int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    while(!isprime(M))
    {
        M++;
    }
    vector<bool > a(M, false);
    for (int i=0;i<N;++i)
    {
        int num,pos;
        scanf("%d",&num);
        pos=num%M;
        if(!a[pos])
        {
            printf("%d",pos);
            a[pos]=true;
        }
        else
        {
            bool flag=false;
            for (int step=1;step<M;step++)
            {
                pos=(num+step*step)%M;
                if(!a[pos])
                {
                    flag=true;
                    printf("%d",pos);
                    a[pos]=true;
                    break;
                }
            }
            if(!flag)
                printf("-");
        }
        if(i!=N-1)
            printf(" ");
    }
    return 0;
}