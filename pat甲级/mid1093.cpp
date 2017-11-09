//
// @author prime on 2017/7/26.
//

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int P=0,A=0;
    long res=0;
    for (auto&e:s)
    {
        if(e=='P')
            P++;
        else if(e=='A')
        {
            A+=P;
        } else
        {
            res+=A;
            res%=1000000007;
        }
    }
    cout<<res;
    return 0;
}


