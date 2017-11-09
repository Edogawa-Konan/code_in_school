//
// @author prime on 2017/6/27.
//

#include <iostream>
#include <deque>
using namespace std;

const int maxn=100002;

int tree[maxn];
deque<int> stack;

int lowbit(int v)
{
    return v&(-v);
}

int read(int idx)
{
    int sum=0;
    while (idx>0)
    {
        sum+=tree[idx];
        idx-=lowbit(idx);
    }
    return sum;
}

void update(int idx,int val)
{
    while(idx<=maxn-1)
    {
        tree[idx]+=val;
        idx+=lowbit(idx);
    }
}

void PeekMedian()
{
    int left=1,right=maxn-1,mid,k=(stack.size()+1)/2;
    while(left < right) {
        mid = (left + right) / 2;
        if(read(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}

int main()
{
    int N;
    char op[12];
    scanf("%d",&N);
    for (int i=0;i<N;++i)
    {
        scanf("%s",op);
        if(op[1]=='o')
        {//pop
            if(stack.empty())
                printf("Invalid\n");
            else
            {
                printf("%d\n",stack.back());
                update(stack.back(),-1);
                stack.pop_back();
            }
        } else if(op[1]=='u')
        {
            int v;
            scanf("%d",&v);
            stack.push_back(v);
            update(v,1);
        }
        else
        {
            if(!stack.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}