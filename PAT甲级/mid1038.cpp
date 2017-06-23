//
// @author prime on 2017/6/22.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const string &o1, const string &o2)
{
    return o1+o2<o2+o1;
}

int main()
{
    int N;
    cin>>N;
    string s[N];
    for (int i=0;i<N;++i)
        cin>>s[i];
    sort(s,s+N,cmp);
    string res;
    for (int i=0;i<N;++i)
        res+=s[i];
    while(res.size()!=0&&res[0]=='0')
    {
        res.erase(res.begin());
    }
    if(res.size()==0)
        cout<<'0';
    else
        cout<<res;
    return 0;
}
