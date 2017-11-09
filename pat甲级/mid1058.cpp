//
// @author prime on 2017/6/28.
//
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int G1,S1,K1,G2,S2,K2;
    scanf("%d.%d.%d",&G1,&S1,&K1);
    scanf("%d.%d.%d",&G2,&S2,&K2);
    G1+=G2;S1+=S2;K1+=K2;
    S1+=K1/29;K1%=29;
    G1+=S1/17;S1%=17;
    printf("%d.%d.%d",G1,S1,K1);
    return 0;
}




