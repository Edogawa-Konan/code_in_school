//
// @author prime on 2017/6/3.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> tree[100];
int res[100];//每一层叶子节点的个数
int total_depth;
void bfs(int index,int depth);

int main()
{
    int m,n;
    cin>>n>>m;
    for (int i = 0; i <m; ++i)
    {
        int id,k;
        cin>>id>>k;
        for (int j = 0; j <k; ++j)
        {
            int tmp;
            cin>>tmp;
            tree[id].push_back(tmp);
        }
    }
    bfs(1,1);
    cout<<res[1];
    for (int l = 2;l<=total_depth; ++l) {
        cout<<" "<<res[l];
    }
}

void bfs(int index,int depth)
{
    deque<int> queue;
    queue.push_back(index);
    queue.push_back(-1);//每一层用-1作为特殊标记
    while(true)
    {
        index=queue[0];
        queue.pop_front();
        if(index==-1)
        {
            depth++;
            if(queue.empty())
                break;
            queue.push_back(-1);
            continue;
        }
        if(tree[index].size()==0)
        {
            res[depth]++;
        } else
        {
            for (int i = 0; i <tree[index].size(); ++i)
            {
                queue.push_back(tree[index][i]);
            }
        }
    }
    total_depth=depth-1;
}