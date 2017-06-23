//
// @author prime on 2017/6/18.
//

#include <iostream>


using namespace std;

bool transform(string& s)
{
    bool flag= false;
    auto it=s.begin();
    while(it!=s.end())
    {
        if(*it=='O')
        {
            *it='o';
            flag=true;
        }
        else if(*it=='1')
        {
            *it='@';
            flag=true;
        } else if(*it=='0')
        {
            *it='%';
            flag=true;
        } else if(*it=='l')
        {
            *it='L';
            flag=true;
        }
        it++;
    }
    return flag;
}

int main()
{
    int N;
    cin>>N;
    pair<string,string> s[N];
    for (int i=0;i<N;++i)
    {
        cin>>s[i].first>>s[i].second;
    }
    int res=0;
    bool modify[N];
    fill(modify,modify+N, false);
    for (int i=0;i<N;++i)
    {
        if(transform(s[i].second))
        {
            res++;
            modify[i]=true;
        }

    }
    if(res>0)
    {
        cout<<res;
        for(int i=0;i<N;++i)
        {
            if(modify[i])
                cout<<"\n"<<s[i].first<<" "<<s[i].second;
        }
    }
    else
    {
        if(N==1)
            cout<<"There is 1 account and no account is modified";
        else
            cout<<"There are "<<N<<" accounts and no account is modified";
    }
    return 0;
}
