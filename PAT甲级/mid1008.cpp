//
// @author prime on 2017/6/4.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum=0,now=0,in;
    for(int i=0;i<n;i++)
    {   cin>>in;
        if(in>now)
            sum+=6*(in-now);
        else
            sum+=4*(now-in);
        now=in;
        sum+=5;
    }
    cout<<sum;
    return 0;

}
