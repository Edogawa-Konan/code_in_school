//
// @author prime on 2017/6/29.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<unordered_set<int>> arr;
    for (int i=0;i<N;++i)
    {
        int M;
        scanf("%d",&M);
        unordered_set<int> s;
        for (int j=0,tmp;j<M;++j)
        {
            scanf("%d",&tmp);
            s.insert(tmp);
        }
        arr.push_back(s);
    }
    int K;
    scanf("%d",&K);
    for (int i=0;i<K;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int nc=0,nt=arr[b-1].size();
        for (auto&e:arr[a-1])
        {
            if(arr[b-1].find(e)==arr[b-1].end())
                nt++;
            else
                nc++;
        }
        printf("%0.1f%\n",(100.0*nc)/nt);
    }
    return 0;
}


