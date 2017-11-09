//
// @author prime on 2017/7/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int N,K,P;
int max_fac_sum=-1;
vector<int> path,tmp_path;


void DFS(int index,int tmp_k,int tmp_sum,int fac_sum)
{//index是数组a的下标，tmp_k记录项的个数，tmp_sum记录因式的和，fac_sum记录底数的和
    if(tmp_k==K&&tmp_sum==N)
    {
        if(fac_sum>max_fac_sum)
        {
            path=tmp_path;
            max_fac_sum=fac_sum;
        }
    }
    else if(tmp_k>K||tmp_sum>N)
        return;
    else if(index>=1)
    {
        tmp_path.push_back(index);
        DFS(index,tmp_k+1,tmp_sum+a[index],fac_sum+index);
        tmp_path.pop_back();
        DFS(index-1,tmp_k,tmp_sum,fac_sum);
    }
}


int main()
{
    scanf("%d%d%d",&N,&K,&P);
    for (int i=0;i<=N;++i)
    {//此处让a[0]=0，后面用不到。
        int t=pow(i,P);
        if(t>N)
            break;
        else
            a.push_back(t);
    }
    DFS(a.size()-1,0,0,0);
    if(path.size()==0)
        printf("Impossible");
    else
    {
        printf("%d = ",N);
        for (int i=0;i<path.size();i++)
        {
            printf("%d^%d",path[i],P);
            if(i!=path.size()-1)
                printf(" + ");
        }
    }
    return 0;
}

