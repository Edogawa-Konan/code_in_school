//
// @author prime on 2017/8/2.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    string name;
    int height;
};

bool cmp(const Node &o1,const Node&o2)
{
    if(o1.height!=o2.height)
        return o1.height>o2.height;
    else
        return o1.name<o2.name;
}


int main()
{
    int N,K;
    cin>>N>>K;
    vector<Node> a(N);
    for (int i=0;i<N;++i)
    {
        cin>>a[i].name>>a[i].height;
    }
    sort(a.begin(),a.end(),cmp);
    int m;//每行m个人
    int Row=K;
    int t=0;
    while(Row)
    {
        if(Row==K)
            m=N-N/K*(K-1);
        else
            m=N/K;
        vector<string> line(m);
        line[m/2]=a[t].name;
        for (int i=m/2-1,j=t+1;j<t+m;j+=2)//先排最高个的右手边
            line[i--]=a[j].name;
        for (int i=m/2+1,j=t+2;j<t+m;j+=2)//再排最高个的左手边
            line[i++]=a[j].name;
        t+=m;
        Row--;
        for (int i=0;i<line.size();i++)
        {
            cout<<line[i];
            if(i!=line.size()-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}

