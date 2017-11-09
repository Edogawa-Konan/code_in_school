//
// @author prime on 2017/7/3.
//
#include <iostream>
/*最后一个用例过不去*/
using namespace std;

int main()
{
    int N;
    cin>>N;
    string s[N];
    getchar();
    int min_len=256;
    for (int i=0;i<N;++i)
    {
        getline(cin,s[i]);
        min_len=min((int)s[i].size(),min_len);
    }
    for (int i=1;i<=min_len;i++)
    {//最多比对min-len个字符
        bool common=true;
        for (int k=1;k<N;k++)
        {
            if(s[k][s[k].size()-i]!=s[0][s[0].size()-i])
            {
                common= false;
                break;
            }
        }
        if(!common)
        {
            if(i==1)
            {
                cout<<"nai";
            } else
            {
                cout<<s[0].substr(s[0].size()-i+1);
            }
            break;
        }
    }
    if(min_len==0)
        cout<<"nai";
    return 0;
}



