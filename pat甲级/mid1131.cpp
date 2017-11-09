//
// @author prime on 2017/9/4.
//

#include <iostream>
#include <vector>

using namespace std;

int line[10000][10000];//保存两个站点之间是几号线
bool visited[10000];
vector<vector<int>> G(10000);//每个结点的邻接结点
vector<int> tmp_path,path;

int transfer_count(vector<int>& tmp)
{//统计一条线路的换乘次数,即简单遍历
    int count=-1,pre=0;
    for (int i=1;i<tmp.size();++i)
    {
        if(line[tmp[i-1]][tmp[i]]!=pre)
        {
            count++;
            pre=line[tmp[i-1]][tmp[i]];
        }
    }
    return count;
}


void DFS(int point,int destination,int count,int &min_count,int &min_transfer)
{
    if(point==destination&&(count<min_count||count==min_count&&transfer_count(tmp_path)<min_transfer))
    {
        min_count=count;
        min_transfer=transfer_count(tmp_path);
        path=tmp_path;
    }
    else if(point==destination)
        return;
    else
    {
        for (auto&e:G[point])
        {
            if(!visited[e])
            {
                visited[e]=true;
                tmp_path.push_back(e);
                DFS(e,destination,count+1,min_count,min_transfer);//每次DFS一次，count加1表示又过了一个站点
                visited[e]=false;
                tmp_path.pop_back();
            }
        }
    }
}




int main()
{
    int N,M,pre,cur,K;
    scanf("%d",&N);
    for (int i=1;i<=N;++i)
    {
        scanf("%d%d",&M,&pre);
        for (int j=1;j<M;++j)
        {
            scanf("%d",&cur);
            G[pre].push_back(cur);
            G[cur].push_back(pre);//构建图
            line[pre][cur]=line[cur][pre]=i;//线路编号
            pre=cur;
        }
    }
    scanf("%d",&K);
    int a,b;//起点和终点的编号
    for (int i=0;i<K;++i)
    {
        scanf("%d%d",&a,&b);
        int min_count=9999,min_transfer=99;//最少经过几站，最少换乘次数
        tmp_path.clear();
        tmp_path.push_back(a);
        visited[a]=true;
        DFS(a,b,0,min_count,min_transfer);
        visited[a]=false;

        printf("%d\n",min_count);
        int pre_line=0,pre_stop=a;
        for (int j=1;j<path.size();++j)
        {
            if(line[path[j-1]][path[j]]!=pre_line)
            {//path[j-1]是转运点
                if(pre_line!=0)//输出该转运点之前的路段
                    printf("Take Line#%d from %04d to %04d.\n",pre_line,pre_stop,path[j-1]);
                pre_line=line[path[j-1]][path[j]];
                pre_stop=path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", pre_line, pre_stop, b);
    }
    return 0;
}


