//
// @author prime on 2017/8/5.
//
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    set<int> s;
    char in[5];
    for (int i=0,tmp;i<N;++i)
    {
        scanf("%s",in);
        tmp=0;
        for (int j=0;j<strlen(in);j++)
        {
            tmp+=in[j]-'0';
        }
        s.insert(tmp);
    }
    printf("%d\n",s.size());
    bool first=true;
    for (auto it=s.begin();it!=s.end();it++)
    {
        if(first)
        {
            printf("%d",*it);
            first=false;
        }
        else
            printf(" %d",*it);

    }
    return 0;
}







