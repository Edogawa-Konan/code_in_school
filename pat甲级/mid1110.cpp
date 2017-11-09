//
// @author prime on 2017/8/3.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Node
{
    int left,right;
};

bool exist[20];

int main()
{
    int N;
    scanf("%d",&N);
    vector<Node> tree(N);
    for (int i=0;i<N;++i)
    {
        char L_tmp[3],R_tmp[3];
        scanf("%s %s",L_tmp,R_tmp);
        int L=-1,R=-1;
        sscanf(L_tmp,"%d",&L);
        sscanf(R_tmp,"%d",&R);
        tree[i].left=L;
        tree[i].right=R;
        if(L!=-1)
            exist[L]=true;
        if(R!=-1)
            exist[R]=true;
    }
    int root;
    for (int i=0;i<N;++i)
    {
        if(!exist[i])
        {
            root=i;
            break;
        }
    }
    deque<int> queue;
    queue.push_back(root);
    int count=0;
    int last=-1;
    while (!queue.empty())
    {
        int t=queue[0];
        queue.pop_front();
        if(t!=-1)
        {
            last=t;
            count++;
        }
        else
        {
            if(count==N)
                printf("YES %d",last);
            else
                printf("NO %d",root);
            break;
        }
        queue.push_back(tree[t].left);
        queue.push_back(tree[t].right);
    }
    return 0;
}

