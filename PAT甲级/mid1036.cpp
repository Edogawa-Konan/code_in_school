//
// @author prime on 2017/6/18.
//
#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    char name[11];//只能写10个字符
    char gender;//性别
    char id[11];
    int grade;
};

bool cmp(const Student& o1,const Student& o2)
{
    return o1.grade>o2.grade;
}

int main()
{
    int N;
    scanf("%d",&N);
    vector<Student> F,M;
    for (int i=0;i<N;++i)
    {
        Student tmp;
        scanf("%s %c %s %d",tmp.name,&tmp.gender,tmp.id,&tmp.grade);
        if(tmp.gender=='F')
            F.push_back(tmp);
        else
            M.push_back(tmp);
    }
    sort(F.begin(),F.end(),cmp);
    sort(M.begin(),M.end(),cmp);
    if(F.size()>0&&M.size()>0)
    {
        printf("%s %s\n%s %s\n",F[0].name,F[0].id,M.back().name,M.back().id);
        printf("%d",F[0].grade-M.back().grade);
    } else if(F.size()>0)
    {
        printf("%s %s\n",F[0].name,F[0].id);
        printf("Absent\n");
        printf("NA");
    } else if(M.size()>0)
    {
        printf("Absent\n");
        printf("%s %s\n",M.back().name,M.back().id);
        printf("NA");
    }
    return 0;
}



