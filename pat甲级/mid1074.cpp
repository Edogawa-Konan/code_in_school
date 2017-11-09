//
// @author prime on 2017/7/2.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int address;//5位
    int val;
    int next;
};


int main()
{
    int start,N,K;
    scanf("%d%d%d",&start,&N,&K);
    vector<Node> in(100000),res;
    for (int i=0,addr;i<N;++i)
    {
        scanf("%d",&addr);
        scanf("%d%d",&in[addr].val,&in[addr].next);
        in[addr].address=addr;
    }
    for (int begin=start;begin!=-1;begin=in[begin].next)
        res.push_back(in[begin]);
    for (auto it=res.begin();it<res.end();it+=K)
        if(it+K<=res.end())
            reverse(it,it+K);
    for (int i=0;i<res.size();++i)
    {
        if(i==res.size()-1)
        {
            printf("%05d %d -1",res[i].address,res[i].val);
            break;
        }
        printf("%05d %d %05d\n",res[i].address,res[i].val,res[i+1].address);
    }
    return 0;
}

