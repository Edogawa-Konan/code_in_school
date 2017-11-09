//
// @author prime on 2017/8/2.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N;
    cin>>N;
    char a[60],b[60];
    double sum=0,tmp=0;
    int count=0;
    for(int i=0;i<N;++i)
    {
        scanf("%s",a);
        sscanf(a,"%lf",&tmp);
        sprintf(b,"%.2lf",tmp);
        bool error= false;
        for (int j=0;j<strlen(a);j++)
        {
            if(a[j]!=b[j])
                error=true;
        }
        if(error||tmp>1000||tmp<-1000)
            printf("ERROR: %s is not a legal number\n",a);
         else
        {
            sum+=tmp;
            count++;
        }
    }
    if(count==0)
        printf("The average of 0 numbers is Undefined\n");
    else if(count==1)
        printf("The average of 1 number is %.2lf\n",sum);
    else
        printf("The average of %d numbers is %.2lf\n",count,sum/count);

    return 0;
}


