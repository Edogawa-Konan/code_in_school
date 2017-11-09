//
// @author prime on 2017/10/7.
//

#include <iostream>

using namespace std;

bool check(const string&s)
{
    int num=s.size();
    int a=stoi(s.substr(0,num/2));
    int b=stoi(s.substr(num/2));
    int c=stoi(s);
    if(a*b!=0&&c%(a*b)==0)
        return true;
    else
        return false;
}

int main()
{
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;++i)
    {
        string in;
        cin>>in;
        if(check(in))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}



