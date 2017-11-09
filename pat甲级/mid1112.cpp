//
// @author prime on 2017/8/3.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int K;
    string s;
    cin>>K>>s;
    unordered_map<char,int> dict;
    unordered_set<char> Nobroken;
    int count,index=0;
    for (int i=0;i<s.size();i+=count)
    {
        count=1;
        for (int j=i+1;s[j]==s[j-1]&&j<s.size();j++)
        {
            count++;
        }
        if(count%K==0)//不是count>=K！！！
        {
            if(dict.find(s[i])==dict.end()&&Nobroken.find(s[i])==Nobroken.end())
                dict[s[i]]=index++;
        }
        else
        {
            Nobroken.insert(s[i]);
            dict.erase(s[i]);
        }
    }
    vector<char> res(index+1);
    fill(res.begin(),res.end(),0);
    for (auto&pt:dict)
    {
        res[pt.second]=pt.first;
    }
    for (auto&c:res)
    {
        if(c!=0)
            printf("%c",c);
    }
    printf("\n");
    for (int i=0;i<s.size();i+=count)
    {
        count=1;
        if(dict.find(s[i])!=dict.end())
        {
            for (int j=i+1;s[j]==s[j-1]&&j<s.size();j++)
            {
                count++;
                if(count%K==0)
                    printf("%c",s[i]);
            }
        }
        else
        {
            printf("%c",s[i]);
            for (int j=i+1;s[j]==s[j-1]&&j<s.size();j++)
            {
                count++;
                printf("%c",s[i]);
            }
        }
    }
    return 0;
}



