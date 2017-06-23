//
// @author prime on 2017/6/11.
//

#include <iostream>
#include <algorithm>

using namespace std;


void add(string &a,string &b)
{
    string res(a.size(),0);
    int carry=0;//是否进位
    for (int i=a.size()-1;i>=0;i--)
    {
        res[i]=a[i]+b[i]-'0'+carry;
        carry=0;
        if(res[i]>'9')
        {
            carry=1;
            res[i]-=10;
        }
    }
    if(carry)
        res='1'+res;
    a=res;
}

int main()
{
    int K;
    string in;
    cin>>in>>K;
    for (int i=0;i<K;++i)
    {
        string b=in;
        reverse(b.begin(),b.end());
        if(b==in)
        {
            cout<<b<<'\n'<<i;
            return 0;
        }
        add(in,b);
    }
    cout<<in<<"\n"<<K;
    return 0;
}



