//
// @author prime on 2017/7/2.
//

#include <iostream>

using namespace std;

int main()
{
    bool sign;
    string in,res;
    cin>>in;
    sign= (in[0]=='+');
    int exponent=0;//题目说了指数不超过9999
    for (int i=1;i<in.size();++i)
    {
        if(in[i]=='E')
        {
            exponent=stoi(in.substr(i+1));
            break;
        }
        if(in[i]!='.')
            res+=in[i];
    }//res保存系数部分，不保存小数点。
    if(exponent>0)
    {
        if(exponent>res.size()-1)
        {
            res.insert(res.size(),exponent-(res.size()-1),'0');
        } else if(exponent<res.size()-1)
        {
            res.insert(1+exponent,1,'.');
        }
    } else if(exponent<0)
    {
        exponent=-exponent;
        res.insert(0,exponent,'0');
        res.insert(1,1,'.');
    }
    else
    {
        res.insert(1,1,'.');
    }
    if(!sign)
        res='-'+res;
    cout<<res;
    return 0;
}



