//
// @author prime on 2017/6/9.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    a+=b;
    string out=to_string(a);
    for (int i=0;i<out.size();++i)
    {
        printf("%c",out[i]);
        if(out[i]=='-')
            continue;
        if((i+1)%3==out.size()%3&&i!=out.size()-1)
            printf(",");
    }
    return 0;
}



