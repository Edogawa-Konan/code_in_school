//
// @author prime on 2017/6/22.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int my_hash(char *name)
{
    int code=0;
    for (int i=0;i<3;++i)
    {
        code=code*26+name[i]-'A';
    }
    code=code*10+name[3]-'0';
    return code;
}

const int max_num=26*26*26*10+10;
vector<int> s[max_num];

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    char name[5];
    for (int i=0;i<K;++i)
    {
        int index,n;
        scanf("%d%d",&index,&n);
        for (int j=0;j<n;++j)
        {
            scanf("%s",name);
            s[my_hash(name)].push_back(index);
        }
    }
    for (int i=0;i<N;++i)
    {
        scanf("%s",name);
        int id=my_hash(name);//在hash表中的位置
        sort(s[id].begin(),s[id].end());
        printf("%s %lld",name,s[id].size());
        for (auto & e:s[id])
            printf(" %d",e);
        printf("\n");
    }
    return 0;
}


