//
// @author prime on 2017/10/7.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int address;
    int val;
    int next;
};

int main()
{
    int start,N,K;
    scanf("%d %d %d",&start,&N,&K);
    vector<Node> tmp(100000);
    vector<Node> s,res;
    for (int i=0;i<N;++i)
    {
        int addr,val,next;
        scanf("%d %d %d",&addr,&val,&next);
        tmp[addr].address=addr;
        tmp[addr].val=val;
        tmp[addr].next=next;
    }
    for (int begin=start;begin!=-1;begin=tmp[begin].next)
    {
        s.push_back(tmp[begin]);
    }
    for (auto&e:s)
    {
        if(e.val<0)
            res.push_back(e);
    }
    for (auto&e:s)
    {
        if(e.val>=0&&e.val<=K)
            res.push_back(e);
    }
    for (auto&e:s)
    {
        if(e.val>K)
            res.push_back(e);
    }
    for (int i=0;i<res.size();++i)
    {
        if(i!=res.size()-1)
            printf("%05d %d %05d\n",res[i].address,res[i].val,res[i+1].address);
        else
            printf("%05d %d -1",res[i].address,res[i].val);
    }
    return 0;
}
