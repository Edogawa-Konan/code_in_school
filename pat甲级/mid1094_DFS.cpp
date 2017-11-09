//
// @author prime on 2017/7/26.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> tree[100];
int population[100];//记录每一层结点的个数

void DFS(int u,int level)
{
    population[level]++;
    for (auto&e:tree[u])
        DFS(e,level+1);
}


int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i)
    {
        int k,id,child;
        scanf("%d%d",&id,&k);
        for (int j=0;j<k;++j)
        {
            scanf("%d",&child);
            tree[id].push_back(child);
        }
    }
    DFS(1,1);
    int max_population=0,point;
    for (int i=1;i<100;i++)
    {
        if(population[i]>max_population)
        {
            max_population=population[i];
            point=i;
        }
    }
    printf("%d %d",max_population,point);
    return 0;
}





