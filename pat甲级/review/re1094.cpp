//
// @author prime on 2017/9/15.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100];
int max_depth=0;
vector<int> res(100);

void DFS(int u,int depth)
{
    res[depth]++;
    for (auto&e:tree[u])
        DFS(e,depth+1);
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;++i)
    {
        int id,k,child;
        scanf("%d %d",&id,&k);
        for (int j=0;j<k;++j)
        {
            scanf("%d",&child);
            tree[id].push_back(child);
        }
    }
    DFS(1,1);
    int max_generation=-1,point=-1;
    for (int i=0;i<res.size();++i)
    {
        if(res[i]>max_generation)
        {
            max_generation=res[i];
            point=i;
        }
    }
    printf("%d %d",max_generation,point);
    return 0;
}



