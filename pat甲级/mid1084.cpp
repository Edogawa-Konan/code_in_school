//
// @author prime on 2017/7/23.
//
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string in,out;
    cin>>in>>out;
    unordered_set<char> s;
    for (int i=0,j=0;i<in.size();++i)
    {
        if(out[j]==in[i])
        {
            j++;
        }
        else
        {
            char C=(char)toupper(in[i]);
            if(s.find(C)!=s.end())
                continue;
            else
            {
                s.insert(C);
                printf("%c",C);
            }
        }
    }
    return 0;
}


