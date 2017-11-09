//
// @author prime on 2017/7/29.
//
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    double arr[N+1];
    double res=0;
    for (int i=1;i<=N;++i)
    {
        cin>>arr[i];
        res=res+i*arr[i]*(N-i+1);
    }
    printf("%.2f",res);
    return 0;
}



