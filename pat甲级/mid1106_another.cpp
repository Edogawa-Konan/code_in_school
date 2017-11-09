//
// @author prime on 2017/7/29.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
double P,R;
vector<int> tree[100000];
int count=0;
int min_depth=99999;

void DFS(int root,int depth)
{
    if(tree[root].empty())
    {
        if(depth<min_depth)
        {
            min_depth=depth;
            count=1;
        } else if(depth==min_depth)
        {
            count++;
        }
    }
    else
    {
        for (auto&e:tree[root])
            DFS(e,depth+1);
    }
}

int main()
{
    scanf("%d%lf%lf",&N,&P,&R);
    R/=100;
    for (int i=0;i<N;++i)
    {
        int k,child;
        scanf("%d",&k);
        for (int j=0;j<k;j++)
        {
            scanf("%d",&child);
            tree[i].push_back(child);
        }
    }
    DFS(0,0);
    printf("%.4lf %d",P*pow((1+R),min_depth),count);
    return 0;
}

