//
// @author prime on 2017/8/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> s(N);
    for (int i=0;i<N;++i)
        cin>>s[i];
    sort(s.begin(),s.end());
    double res=s[0];
    for (int i=1;i<N;++i)
    {
        res=(res+s[i])/2;
    }
    printf("%d",(int)res);
    return 0;
}



