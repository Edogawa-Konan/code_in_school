//
// @author prime on 2017/6/16.
//

#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

struct Node
{
    char val;
    int next;
    Node()= default;
    Node(char v,int n)
    {
        val=v;
        next=n;
    }
    friend bool operator==(const Node&o1,const Node&o2)
    {
        return o1.val==o2.val&&o1.next==o2.next;
    }
    /*friend bool operator<(const Node &o1,const Node& o2)
    {
        if(o1.val<o2.val)
            return true;
        else if(o1.val==o2.val&&o1.next<o2.next)
            return true;
        else
            return false;
    }*/
};


int main()
{
    unordered_set<Node> s;
    s.insert(Node('a',17));
    s.insert(Node('a',13));

    /*if(s.find(Node('a',14))!=s.end())
        cout<<true;
    for (auto &e:s)
        printf("%c:%d ",e.val,e.next);*/

   /* map<int,Node> m;
    int start1,start2,N;
    scanf("%d %d %d",&start1,&start2,&N);
    for (int i=0;i<N;++i)
    {
        int addr,next;char val;
        scanf("%d %c %d",&addr,&val,&next);
        m[addr]=Node(val,next);
    }

    unordered_set<Node,equal_to<Node>> s;
    for (int begin=start1;begin!=-1;begin=m[begin].next)
    {
        s.insert(m[begin]);
    }



    for (int begin=start2;begin!=-1;begin=m[begin].next)
    {
        auto it=s.find(m[begin]);
        if(it!=s.end())
        {
            printf("%05d",begin);
            return 0;
        }
    }
    printf("-1");*/
    return 0;
}



