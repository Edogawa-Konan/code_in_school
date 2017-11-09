//
// @author prime on 2017/7/1.
//
#include <iostream>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    string input,tmp;
    getline(cin,input);
    map<string,int> dict;
    for (int i=0;i<input.size();++i)
    {
        if(isalnum(input[i]))
        {
            input[i]=tolower(input[i]);
            tmp+=input[i];
        }
        else
        {
            if(tmp.size()>0)
            {
                dict[tmp]++;
            }
            tmp="";
        }
    }
    if(tmp.size()>0)
        dict[tmp]++;
    int maxn=-1;
    string res;
    for (auto & d:dict)
    {
        if(d.second>maxn)
        {

            res=d.first;
            maxn=d.second;
        }
    }
    cout<<res<<" "<<dict[res];
    return 0;
}




