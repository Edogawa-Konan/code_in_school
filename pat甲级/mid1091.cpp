//
// @author prime on 2017/7/25.
//

#include <iostream>
#include <deque>
using namespace std;

struct Node
{
    int x,y,z;
    Node(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
    Node()= default;
};

int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};

int M,N,L,T;
int a[1300][150][80];
bool visited[1300][150][80];

bool check(int x,int y,int z)
{
    if(x<0||x>=M||y<0||y>=N||z<0||z>=L)
        return false;
    if(visited[x][y][z]||a[x][y][z]==0)
        return false;
    return true;
}

int BFS(int x,int y,int z)
{
    int count=0;
    Node t(x,y,z);
    deque<Node> queue;
    visited[x][y][z]=true;
    queue.push_back(t);
    while (!queue.empty())
    {
        t=queue[0];
        queue.pop_front();
        for (int i=0;i<6;i++)
        {
            if(check(t.x+X[i],t.y+Y[i],t.z+Z[i]))
            {

                queue.push_back(Node (t.x+X[i],t.y+Y[i],t.z+Z[i]));
                visited[t.x+X[i]][t.y+Y[i]][t.z+Z[i]]=true;
            }
        }
        count++;
    }
    if(count>=T)
        return count;
    else
        return 0;
}




int main()
{
    scanf("%d%d%d%d",&M,&N,&L,&T);
    for (int k=0;k<L;++k)
        for (int i=0;i<M;i++)
            for (int j=0;j<N;++j)
                scanf("%d",&a[i][j][k]);

    int res=0;
    for (int k=0;k<L;++k)
        for (int i=0;i<M;i++)
            for (int j=0;j<N;++j)
            {
                if(a[i][j][k]==1&&!visited[i][j][k])
                    res+=BFS(i,j,k);
            }
    printf("%d",res);
    return 0;
}


