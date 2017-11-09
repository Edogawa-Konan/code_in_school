//
// @author prime on 2017/6/24.
//
#include <iostream>
#include <vector>
using namespace std;

int N,M;

int binary_search(int i,int &pos,vector<int>& sum)
{
    int end=N,begin=i,mid;
    int res=INT32_MAX;
    //注意，题目中M最大一亿，所以，一开始我设置99999999就错误了。这里因为只是用于比较，不会相加，所以直接弄到最大。毕竟不会溢出
    //其实这里设置成10000 0001也可以通过
    while (begin<=end)
    {
        mid=(begin+end)/2;
        if(sum[mid]-sum[i-1]==M)
        {
            pos=mid;
            res=M;
            break;
        }
        else if(sum[mid]-sum[i-1]>M)
        {
            end=mid-1;
            if(sum[mid]-sum[i-1]<res)
            {
                res=sum[mid]-sum[i-1];
                pos=mid;
            }
        } else
        {
            begin=mid+1;
        }
    }
    return res;//res记录从起点i开始，满足要求的连续子串和
}

int main()
{
    scanf("%d%d",&N,&M);
    vector<int> sum(N+1);
    sum[0]=0;
    for (int i=1;i<=N;++i)
    {
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    int min_v=sum[N];//不能正好支付时，就是支付的最少的钱；否则就是M
    vector<int> res;
    for (int i=1;i<=N;++i)
    {//i是查找的起点
        int pos;//每次查找的终点
        int tmp=binary_search(i,pos,sum);
        if(tmp>min_v)
        {
            continue;
        }
        else if(tmp<min_v)
        {
            min_v=tmp;
            res.clear();
            res.push_back(i);
            res.push_back(pos);
        }
        else
        {
            res.push_back(i);
            res.push_back(pos);
        }
    }
    for (int i=0;i<res.size()-1;i+=2)
        printf("%d-%d\n",res[i],res[i+1]);
    return 0;
}

