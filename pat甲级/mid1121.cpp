//
// @author prime on 2017/8/5.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int> couple(100000,-1);//配对表
    vector<bool> come(100000,false);//表示是否来了
    for (int i=0;i<N;++i)
    {
        int id1,id2;
        scanf("%d%d",&id1,&id2);
        couple[id1]=id2;
        couple[id2]=id1;
    }
    int M;
    scanf("%d",&M);
    set<int> res;
    for (int i=0;i<M;++i)
    {
        int id;
        scanf("%d",&id);
        if(couple[id]==-1)
            res.insert(id);
        else
        {
            come[id]=true;
            if(come[couple[id]])
            {
                res.erase(couple[id]);
            }
            else
            {
                res.insert(id);
            }
        }
    }
    printf("%d\n",res.size());
    bool first=true;
    for(auto&e:res)
    {
        if(first)
        {
            first=false;
            printf("%05d",e);
        } else
            printf(" %05d",e);
    }
    return 0;
}



