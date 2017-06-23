//
// @author prime on 2017/6/23.
//

#include <iostream>

using namespace std;

int main()
{
    int K;
    scanf("%d",&K);
    int shuffle[55];//第一个不用
    int start[55],end[55];//先用1~52代表扑克牌。
    for (int i=1;i<=54;++i)
    {
        scanf("%d",&shuffle[i]);
        end[i]=i;
    }
    for (int i=0;i<K;++i)
    {
        for(int j=1;j<=54;++j)//拷贝
            start[j]=end[j];
        for (int j=1;j<=54;++j)
        {
            end[shuffle[j]]=start[j];
        }
    }
    char sign[6]={"SHCDJ"};
    for(int i=1;i<=54;++i)
    {
        end[i]-=1;
        printf("%c%d",sign[end[i]/13],end[i]%13+1);
        if(i!=54)
            printf(" ");
    }
    return 0;
}



