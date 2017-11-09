//
// @author prime on 2017/6/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[101];
vector<int> weight;
vector<vector<int>> res;
vector<int> tmp_path;
int N,M,S;
int total_weight=0;

bool cmp(const vector<int> &o1,const vector<int> &o2)
{
    auto end=min(o1.size(),o2.size());
    for (int i=0;i<end;++i)
    {
        if(o1[i]>o2[i])
            return true;
        else if(o1[i]<o2[i])
            return false;
        else
            continue;
    }
    return true;
}

void DFS(int root)
{
    tmp_path.push_back(weight[root]);
    total_weight+=weight[root];
    if(total_weight>S)
        goto next;
    if(tree[root].empty())
    {//已到达根节点
        if(total_weight==S)
            res.push_back(tmp_path);
    }
    else
    {
        for (auto e:tree[root])
            DFS(e);
    }
    next:
    tmp_path.pop_back();
    total_weight-=weight[root];
}


int main()
{
    scanf("%d%d%d",&N,&M,&S);
    weight.resize(N);
    for (int i=0;i<N;++i)
        scanf("%d",&weight[i]);
    for (int i=0;i<M;++i)
    {
        int id,k,child;
        scanf("%d%d",&id,&k);
        for (int j=0;j<k;++j)
        {
            scanf("%d",&child);
            tree[id].push_back(child);
        }
    }
    DFS(0);
    sort(res.begin(),res.end(),cmp);
    for(auto & arr:res)
    {
        for (int i=0;i<arr.size();++i)
        {
            if(i!=arr.size()-1)
                printf("%d ",arr[i]);
            else
                printf("%d",arr[i]);
        }
        printf("\n");
    }
    return 0;
}



