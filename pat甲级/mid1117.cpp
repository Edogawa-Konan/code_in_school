//
// @author prime on 2017/8/4.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int> s(N+1);
    for(int i=1;i<=N;i++)
        scanf("%d",&s[i]);
    sort(s.begin()+1,s.end(),greater<int>());
    int count=0;
    for (int i=1;i<s.size()&&s[i]>i;i++,count++);
    printf("%d",count);
    return 0;
}
