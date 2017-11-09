//
// @author prime on 2017/7/29.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
double P,R;
vector<int> tree[100000];
double min_price=99999999;
int count=0;

void DFS(int root, double price)
{
    if(tree[root].empty())
    {
        if(price<min_price)
        {
            count=1;
            min_price=price;
        }
        else if(price==min_price)
        {
            count++;
        }
    }
    else
    {
        for (auto&e:tree[root])
            DFS(e,price*(1.0+R));
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
    DFS(0,P);
    printf("%.4lf %d",min_price,count);
    return 0;
}

