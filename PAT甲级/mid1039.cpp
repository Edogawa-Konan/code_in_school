//
// @author prime on 2017/6/22.
//
#include <iostream>
//#include <map>
#include <set>
#include <unordered_map>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N,K;
    cin>>N>>K;
    unordered_map<string,set<int>> course;
    for (int i=0;i<K;++i)
    {
        int index,n;
        string name;
        cin>>index>>n;
        for (int j=0;j<n;++j)
        {
            cin>>name;
            course[name].insert(index);
        }
    }
    string query;
    for (int i=0;i<N;++i)
    {
        cin>>query;
        cout<<query<<" "<<course[query].size();
        for (auto &e:course[query])
            cout<<" "<<e;
        cout<<"\n";
    }
    return 0;
}


