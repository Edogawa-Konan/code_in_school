//
// @author prime on 2017/9/10.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Student
{
    int rank[4];//A C M E
    int name;
    int best;//最好的下标0~3
    int score[4];//A C M E
};

int point=0;

bool cmp(const Student &o1,const Student &o2)
{
    return o1.score[point]>o2.score[point];
}

int main()
{
    char course[4]={'A','C','M','E'};
    int N,M;
    scanf("%d%d",&N,&M);
    vector<Student> s(N);
    for(int i=0;i<N;++i)
    {
        scanf("%d %d %d %d",&s[i].name,&s[i].score[1],&s[i].score[2],&s[i].score[3]);
        s[i].score[0]=round((s[i].score[1]+s[i].score[2]+s[i].score[3])/3.0);
    }
    for (point=0;point<=3;point++)
    {
        sort(s.begin(),s.end(),cmp);
        s[0].rank[point]=1;
        for (int i=1;i<s.size();++i)
        {
            if(s[i].score[point]==s[i-1].score[point])
            {
                s[i].rank[point]=s[i-1].rank[point];
            } else
                s[i].rank[point]=i+1;
        }
    }
    unordered_map<int,int> dict;//名字映射到下标
    for (int i=0;i<s.size();++i)
    {
        s[i].best=0;
        for (point=1;point<=3;point++)
        {
            if(s[i].rank[point]<s[i].rank[s[i].best])
            {
                s[i].best=point;
            }
        }
        dict[s[i].name]=i;
    }
    for (int i=0;i<M;++i)
    {
        int id;
        scanf("%d",&id);
        if(dict.find(id)==dict.end())
            printf("N/A\n");
        else
        {
            int index=dict[id];
            printf("%d %c\n",s[index].rank[s[index].best],course[s[index].best]);
        }
    }
    return 0;
}



