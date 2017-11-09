//
// @author prime on 2017/6/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    vector<int> a(N);
    for (int i=0;i<N;++i)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    for (int i=0;i<N-1;++i)
    {

        int target=M-a[i];
        if(binary_search(a.begin()+i+1,a.end(),target))//从i+1开始查找
        {
            printf("%d %d",a[i],M-a[i]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}



