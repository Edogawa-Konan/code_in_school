//
// @author prime on 2017/6/26.
//
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int M,N;
    int color;
    unordered_map<int,int> dict;
    int max_p=-1,point=0;
    scanf("%d%d",&M,&N);
    for (int i=0;i<N;++i)
        for (int j=0;j<M;j++)
        {
            scanf("%d",&color);
            if(dict.find(color)==dict.end())
            {
                dict[color]=1;
            } else
            {
                dict[color]++;
            }
            if(dict[color]>M*N/2&&dict[color]>max_p)
            {
                max_p=dict[color];
                point=color;
            }
        }
    printf("%d",point);
    return 0;
}


