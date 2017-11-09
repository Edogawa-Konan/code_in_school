//
// @author prime on 2017/7/27.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node
{
    int address;
    int val;
    int next;
    bool is_remove;
};

int main()
{
    int address,N;
    scanf("%d%d",&address,&N);
    vector<Node> tmp(100000);
    for (int i=0;i<N;++i)
    {
        int addr;
        scanf("%d",&addr);
        scanf("%d%d",&tmp[addr].val,&tmp[addr].next);
        tmp[addr].address=addr;
    }
    vector<Node> s;
    for (int point=address;point!=-1;point=tmp[point].next)
    {
        s.push_back(tmp[point]);
    }
    unordered_set<int> set;
    for (auto&e:s)
    {
        if(set.find(abs(e.val))!=set.end())
        {
            e.is_remove=true;
        }
        else
            set.insert(abs(e.val));
    }
    bool first=true,valid= false;//第一个单独处理
    for(int i=0;i<s.size();i++)
    {
        if(!s[i].is_remove)
        {
            if(first)
            {
                printf("%05d %d ",s[i].address,s[i].val);
                first= false;
            } else
            {
                printf("%05d\n%05d %d ",s[i].address,s[i].address,s[i].val);
            }
            valid=true;
        }
    }
    if(valid)
        printf("-1\n");
    first=true,valid= false;//valid表示列表是否为空
    for(int i=0;i<s.size();i++)
    {
        if(s[i].is_remove)
        {
            if(first)
            {
                printf("%05d %d ",s[i].address,s[i].val);
                first= false;
            } else
            {
                printf("%05d\n%05d %d ",s[i].address,s[i].address,s[i].val);
            }
            valid=true;
        }
    }
    if(valid)
        printf("-1\n");
    return 0;
}


