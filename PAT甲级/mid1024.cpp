//
// @author prime on 2017/6/11.
//

#include <iostream>
#include <vector>

using namespace std;

bool is_palindromic(const vector<int> &a)
{
    bool flag=true;
    if(a.size()==1)
        return true;
    for (auto pre=a.cbegin(),it=a.cend()-1;pre!=it;pre++,it--)
    {
        if(*pre!=*it)
        {
            flag= false;
            break;
        }
    }
    return flag;
}


void add(vector<int> &a)
{
    auto it=a.begin(),re=a.end()-1;
    vector<int> tmp;
    while (it!=a.end())
    {
        tmp.push_back(*it+*re);
        it++;re--;
    }
    for (int i=tmp.size()-1;i>0;--i)
    {
        if(tmp[i]>9)
        {
            tmp[i-1]+=tmp[i]/10;
            tmp[i]%=10;
        }
    }
    if(tmp[0]>9)
    {
        tmp.insert(tmp.begin(),0);
        tmp[0]=tmp[1]/10;
        tmp[1]%=10;
    }
    a=tmp;
}


int main()
{
    string input;
    int k;
    cin>>input>>k;
    vector<int> a;
    for (auto & e:input)
    {
        a.push_back(e-'0');
    }
    int total=0;
    for (int i=0;i<k;i++)
    {
        if(is_palindromic(a))
            goto YES;
        add(a);
        total++;
    }
    for (auto &e:a)
        cout<<e;
    cout<<'\n'<<k;
    return 0;

    YES:
    for (auto &e:a)
        cout<<e;
    cout<<'\n'<<total;
    return 0;
}





