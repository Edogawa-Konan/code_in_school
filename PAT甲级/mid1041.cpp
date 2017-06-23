//
// @author prime on 2017/6/23.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main()
{
    int N;
    scanf("%d",&N);
    vector<int> in(N);
    unordered_map<int,int> dict;
    for (int i=0;i<N;++i)
    {
        scanf("%d",&in[i]);
        if(dict.find(in[i])==dict.end())
            dict[in[i]]=1;
        else
            dict[in[i]]++;
    }

    for (int i=0;i<N;++i)
    {
        if(dict[in[i]]==1)
        {
            printf("%d",in[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}