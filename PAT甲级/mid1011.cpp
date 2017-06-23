//
// @author prime on 2017/6/4.
//

#include <iostream>

using namespace std;

int main()
{
    float res[3];
    char choice[3];
    float a,b,c;
    for(int i=0;i<3;i++)
    {
        scanf("%f %f %f",&a,&b,&c);
        if(a>=b&&a>=c)
        {
            res[i]=a;
            choice[i]='W';
        } else if(b>=a&&b>=c)
        {
            res[i]=b;
            choice[i]='T';
        } else if(c>=a&&c>=b)
        {
            res[i]=c;
            choice[i]='L';
        }
    }
    double profit=(res[0]*res[1]*res[2]*0.65-1)*2;
    printf("%c %c %c %.2f",choice[0],choice[1],choice[2],profit);
    return 0;
}


