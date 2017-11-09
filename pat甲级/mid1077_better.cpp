//
// @author prime on 2017/7/3.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin>>N;
    getchar();//吃掉换行符
    string s[N];
    for (int i=0;i<N;++i)
    {
        getline(cin,s[i]);
        reverse(s[i].begin(),s[i].end());
    }
    string res=s[0];
    for (int i=1;i<N;++i)
    {
        int end=min((int)res.size(),(int)s[i].size());
        for (int k=0;k<end;k++)
        {
            if(res[k]!=s[i][k])
            {
                res=res.substr(0,k);
                break;
            }
        }
    }
    if(res.size()==0)
        cout<<"nai";
    else
    {
        for (auto it=res.rbegin();it!=res.rend();it++)
            cout<<*it;
    }
    return 0;
}


