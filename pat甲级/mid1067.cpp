//
// @author prime on 2017/7/1.
//


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int> pos(N);
    int total=0;//统计有多少个数不在其位
    for (int i=0,a;i<N;++i)
    {
        scanf("%d",&a);
        pos[a]=i;
        if(a!=i&&a!=0)
            total++;
    }
    int index=1;//第一个不在原本位置上的数的下标
    int res=0;//需要交换的总次数
    while(total!=0)
    {
        if(pos[0]!=0)
        {//0在i位上，就把0和i的位置对换，这样i归位
            swap(pos[0],pos[pos[0]]);
            res++;
            total--;
        }
        else
        {
            for (;index<N;++index)
            {
                if(pos[index]!=index)
                    break;
            }
            swap(pos[index],pos[0]);
            res++;
        }
    }
    printf("%d",res);
    return 0;
}
