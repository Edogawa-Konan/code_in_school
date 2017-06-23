//
// @author prime on 2017/6/13.
//



#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n1,n2;
    scanf("%d",&n1);
    vector<long int> a(n1);
    for (int i=0;i<n1;++i)
        scanf("%ld",&a[i]);
    scanf("%d",&n2);
    vector<long int> b(n2);
    for (int i=0;i<n2;++i)
        scanf("%ld",&b[i]);

    auto p1=a.cbegin(),p2=b.cbegin();
    int count=(n1+n2-1)/2;//舍弃这么多的数字
    while(count!=0)
    {
        if(p1==a.cend())
        {
            p2++;
            goto next;
        }
        if(p2==b.cend())
        {
            p1++;
            goto next;
        }
        if(*p1<=*p2)
            p1++;
        else
            p2++;
        next:
        count--;
    }
    long res;
    if(p1!=a.cend()&&p2!=b.cend())
        res=*p1>*p2?*p2:*p1;
    else
        res=p1==a.cend()?*p2:*p1;
    printf("%ld",res);

    return 0;
}




