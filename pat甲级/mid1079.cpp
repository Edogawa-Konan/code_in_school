//
// @author prime on 2017/7/4.
//
#include <iostream>
#include <vector>


using namespace std;

double total_sale=0;

double R;

vector<int> tree[100000];
int product[100000];//记录零售商i的商品数量

void DFS(int u, double price)
{
    if(tree[u].size()==0)
    {
        total_sale+=product[u]*price;
    }
    else
    {
        for (int i=0;i<tree[u].size();++i)
            DFS(tree[u][i],(1+R)*price);
    }
}


int main()
{
    int N;
    double P;
    scanf("%d %lf %lf",&N,&P,&R);
    R/=100;
    for (int i=0;i<N;++i)
    {
        int num;
        scanf("%d",&num);
        if(num==0)
        {
            scanf("%d",&product[i]);
            continue;
        }
        for (int j=0;j<num;++j)
        {
            int id;
            scanf("%d",&id);
            tree[i].push_back(id);
        }
    }
    DFS(0,P);
    printf("%.1lf",total_sale);
    return 0;
}
