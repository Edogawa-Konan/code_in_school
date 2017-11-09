//
// @author prime on 2017/7/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student
{
    char name[11];
    char id[11];
    int score;
};
bool cmp(const Student&o1,const Student&o2)
{
    return o1.score>o2.score;
}

int main()
{
    int N;
    scanf("%d",&N);
    vector<Student> s(N);
    for(int i=0;i<N;++i)
    {
        scanf("%s %s %d",s[i].name,s[i].id,&s[i].score);
    }
    int a,b;
    scanf("%d%d",&a,&b);
    sort(s.begin(),s.end(),cmp);
    bool has=false;
    for (auto&e:s)
    {
        if(e.score<a)
            break;
        if(e.score>=a&&e.score<=b)
        {
            printf("%s %s\n",e.name,e.id);
            has=true;
        }
    }
    if(!has)
        printf("NONE");
    return 0;
}

