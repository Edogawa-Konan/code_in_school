//
// @author prime on 2017/6/1.
//

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> tree[100];//tree[i]表示编号为i的结点的孩子们的编号
int res[100];//某一层的叶子节点数
void dfs(int i,int depth);
static int total_depth=-1;//最多有几层？从1开始

int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    for (int i = 0; i <m ; ++i)
    {
        int id,k;
        scanf("%d %d",&id,&k);
        for(int j=1;j<=k;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            tree[id].push_back(tmp);
        }
    }
    dfs(1,1);
    for (int i = 1; i <total_depth; ++i)
    {
        printf("%d ",res[i]);
    }
    printf("%d",res[total_depth]);
    return 0;
}

void dfs(int index,int depth)
{//index表示结点编号,经典的dfs
    if(tree[index].size()==0)
    {//如果没有孩子，那么这一层叶子结点数+1
        res[depth]++;
        total_depth=max(total_depth,depth);
    }
    else
    {//有孩子就递归调用
        for (int j = 0; j<tree[index].size(); ++j) {
            dfs(tree[index][j],depth+1);
        }
    }
}


