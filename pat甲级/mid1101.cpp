//
// @author prime on 2017/7/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int> a(N),b;
    for (int i=0;i<N;++i)
        scanf("%d",&a[i]);
    b=a;
    sort(b.begin(),b.end());
    vector<int> res;
    int left_max=0;
    for (int i=0;i<N;++i)
    {
        if(a[i]==b[i]&&a[i]>left_max)
            res.push_back(a[i]);
        if(a[i]>left_max)
            left_max=a[i];
    }
    printf("%d\n",res.size());
    for (int i=0;i<res.size();++i)
    {
        printf("%d",res[i]);
        if(i!=res.size()-1)
            printf(" ");
    }
    printf("\n");
    //不加这句的话会有一个测试点没法通过。。。大部分测试用例结尾不输出换行符都可以通过。
    // 只有一个出现格式错误，是由于该测试点为特例，其结果为0。没有换行符其结果只有一行～
    return 0;
}


