//
// @author prime on 2017/8/13.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node
{
    int index,times;
    Node()= default;
    Node(int i,int v):index(i),times(v) {};
    friend bool operator<(const Node &o1,const Node&o2)
    {
        if(o1.times!=o2.times)
            return o1.times>o2.times;
        else
            return o1.index<o2.index;
    }
};


int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    set<Node> s;
    vector<int> count(N+1,0);
    for (int i=1;i<=N;++i)
    {
        int id;
        scanf("%d",&id);
        if(i!=1)
        {
            printf("%d:",id);
            int tmp=0;
            for (auto it=s.begin();it!=s.end()&&tmp<K;it++,tmp++)
                printf(" %d",it->index);
            printf("\n");
        }
        auto it=s.find(Node(id,count[id]));
        if(it!=s.end())
            s.erase(it);
        s.insert(Node(id,++count[id]));
    }
    return 0;
}



