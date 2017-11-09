//
// @author prime on 2017/6/29.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct People
{
    int talent,virtue;
    int id;
};

bool cmp(const People&o1,const People&o2)
{
    if((o1.virtue+o1.talent)!=(o2.virtue+o2.talent))
        return (o1.virtue+o1.talent)>(o2.virtue+o2.talent);
    else
    {
        if(o1.virtue!=o2.virtue)
            return o1.virtue>o2.virtue;
        else
            return o1.id<o2.id;
    }
}

int main()
{
    int N,L,H;
    scanf("%d%d%d",&N,&L,&H);
    vector<People> sage,nobleman,foolman,smallman;
    for (int i=0;i<N;++i)
    {
        People tmp;
        scanf("%d%d%d",&tmp.id,&tmp.virtue,&tmp.talent);
        if(tmp.talent<L||tmp.virtue<L)
            continue;
        else if(tmp.virtue>=H&&tmp.talent>=H)
            sage.push_back(tmp);
        else if(tmp.virtue>=H&&tmp.talent<H)
            nobleman.push_back(tmp);
        else if(tmp.virtue>=tmp.talent)
            foolman.push_back(tmp);
        else if(tmp.talent>tmp.virtue)
            smallman.push_back(tmp);
    }
    sort(sage.begin(),sage.end(),cmp);
    sort(nobleman.begin(),nobleman.end(),cmp);
    sort(foolman.begin(),foolman.end(),cmp);
    sort(smallman.begin(),smallman.end(),cmp);
    printf("%lld\n",sage.size()+nobleman.size()+foolman.size()+smallman.size());
    for (auto &e:sage)
        printf("%08d %d %d\n",e.id,e.virtue,e.talent);
    for (auto &e:nobleman)
        printf("%08d %d %d\n",e.id,e.virtue,e.talent);
    for (auto &e:foolman)
        printf("%08d %d %d\n",e.id,e.virtue,e.talent);
    for (auto &e:smallman)
        printf("%08d %d %d\n",e.id,e.virtue,e.talent);
    return 0;
}


