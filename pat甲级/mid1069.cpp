//
// @author prime on 2017/7/1.
//

#include <iostream>
#include <algorithm>

using namespace std;

void process(string num)
{
    string a,b;
    int ia,ib;
    num.insert(0,4-num.size(),'0');
    do
    {
        sort(num.begin(),num.end(),greater<char>());
        a=num;
        sort(num.begin(),num.end(),less<char>());
        b=num;
        if(a==b)
        {
            cout<<num<<" - "<<num<<" = 0000";
            break;
        }
        ia=stoi(a);
        ib=stoi(b);
        num=to_string(ia-ib);
        num.insert(0,4-num.size(),'0');
        cout<<a<<" - "<<b<<" = "<<num<<endl;
    }while(num!="6174");
}


int main()
{
    string num,a,b;
    cin>>num;
    process(num);
    return 0;
}

