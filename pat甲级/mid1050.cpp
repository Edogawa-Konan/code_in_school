//
// @author prime on 2017/6/25.
//

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    unordered_set<char> remove;
    for (auto &e:s2)
    {
        remove.insert(e);
    }
    for (auto &e:s1)
    {
        if(remove.find(e)!=remove.end())
        {//存在于集合中
            continue;
        }
        else
        {
            printf("%c",e);
        }
    }
    return 0;
}



