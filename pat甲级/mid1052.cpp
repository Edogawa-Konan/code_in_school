//
// @author prime on 2017/6/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int addr;
    int val;
    int next;
};

bool cmp(const Node&o1,const Node& o2)
{
    return o1.val<o2.val;
}

int main()
{
    int N,start;
    scanf("%d %d",&N,&start);
    vector<Node> s(100001);
    for (int i=0;i<N;++i)
    {
        int addr;
        scanf("%d",&addr);
        scanf("%d %d",&s[addr].val,&s[addr].next);
        s[addr].addr=addr;
    }
    vector<Node> res;
    for(int point=start;point!=-1;point=s[point].next)
    {
        res.push_back(s[point]);
    }
    sort(res.begin(),res.end(),cmp);
    if(res.size()>0)
        printf("%d %05d\n",res.size(),res[0].addr);
    else
        printf("0 -1\n");
    for (int i=0;i<res.size();++i)
    {
        if(i==res.size()-1)
        {
            printf("%05d %d %d",res[i].addr,res[i].val,-1);
        }
        else
        {
            printf("%05d %d %05d\n",res[i].addr,res[i].val,res[i+1].addr);
        }
    }
    return 0;
}