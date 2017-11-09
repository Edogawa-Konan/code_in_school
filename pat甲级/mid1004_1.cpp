//
// @author prime on 2017/9/6.
//


#include <iostream>
#include <vector>
#include <deque>


using namespace std;

vector<int> tree[100];
int level[100];//打表记录每个id所在层数
int res[100];//记录每一层的叶子结点个数
int total_depth=0;

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;++i)
    {
        int id,k,child_id;
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;++j)
        {
            scanf("%d",&child_id);
            tree[id].push_back(child_id);
        }
    }
    deque<int> q;
    q.push_back(1);
    level[1]=1;
    while (!q.empty())
    {
        int t=q[0];
        q.pop_front();
        total_depth=max(level[t],total_depth);//更新最大深度为了后面输出！
        if(tree[t].size()==0)
            res[level[t]]++;
        else
        {
            for (auto&child:tree[t])
            {
                q.push_back(child);
                level[child]=level[t]+1;
            }
        }
    }
    for (int i=1;i<=total_depth;++i)
    {
        printf("%d",res[i]);
        if(i!=total_depth)
            printf(" ");
    }
    return 0;
}


