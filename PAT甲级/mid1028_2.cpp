//
// @author prime on 2017/6/13.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student
{
    int id;
    char name[10];
    int score;
};

bool cmp_id(const Student& o1, const Student& o2)
{
    return o1.id<o2.id;
}

bool cmp_name(const Student& o1,const Student&o2)
{
    //return o1.name!=o2.name?o1.name<o2.name:o1.id<o2.id;
    return strcmp(o1.name,o2.name)<=0;
}

bool cmp_score(const Student&o1,const Student&o2)
{
    //return o1.score!=o2.score?o1.score<o2.score:o1.id<o2.id;
    return o1.score<=o2.score;
}

//最后一个测试点超大，string会超时。。。

int main()
{
    int N,C;
    scanf("%d%d",&N,&C);
    vector<Student> s(N);
    for (int i=0;i<N;i++)
    {
        scanf("%d %s %d",&s[i].id,s[i].name,&s[i].score);
    }
    switch (C)
    {
        case 1:
            sort(s.begin(),s.end(),cmp_id);
            break;
        case 2:
            sort(s.begin(),s.end(),cmp_name);
            break;
        case 3:
            sort(s.begin(),s.end(),cmp_score);
            break;
    }
    for (int i=0;i<N;++i)
    {
        printf("%06d %s %d\n",s[i].id,s[i].name,s[i].score);
    }
    return 0;
}


