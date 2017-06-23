//
// @author prime on 2017/6/16.
//

#include <iostream>

using namespace std;

struct Node
{
    char val;
    int next;
    bool flag;
    Node()= default;
    Node(char v,int n)
    {
        flag= false;
        this->val=v;
        this->next=n;
    }
};

int main()
{
    Node s[100000];
    int N,start1,start2;
    scanf("%d%d%d",&start1,&start2,&N);
    for(int i=0;i<N;++i)
    {
        int addr,n;
        char v;
        scanf("%d %c %d",&addr,&v,&n);
        s[addr].next=n;
        s[addr].val=v;
    }
    for (int begin=start1;begin!=-1;begin=s[begin].next)
    {
        s[begin].flag= true;
    }
    for (int begin=start2;begin!=-1;begin=s[begin].next)
    {
        if(s[begin].flag)
        {
            printf("%05d",begin);
            return 0;
        }
    }
    printf("-1");
    return 0;
}



