//
// @author prime on 2017/6/26.
//
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int M,N,K;

bool check(vector<int> &s)
{
   // bool flag=true;
    deque<int> stack;
    int current=0;
    for (int i=1;i<=N;++i)//将1~N序列依次进栈
    {
        stack.push_back(i);
        if(stack.size()>M)
        {
            return false;
        }
        while(!stack.empty()&&stack.back()==s[current])
        {
            stack.pop_back();
            current++;
        }
    }
    return current==N;//等于N说明都匹配了，否则说明未匹配完全且栈未溢出
}


int main()
{
    scanf("%d%d%d",&M,&N,&K);
    vector<int> a(N);
    for(int i=0;i<K;++i)
    {
        for (int j=0;j<N;++j)
        {
            scanf("%d",&a[j]);
        }
        if(check(a))
        {
            printf("YES\n");
        } else
            printf("NO\n");
    }
    return 0;
}


