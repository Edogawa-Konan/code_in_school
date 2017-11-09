//
// @author prime on 2017/7/5.
//

//
// @author prime on 2017/7/4.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int Ge,Gi;
    int choice[5];
    int rank;
    int total;
};

struct School
{
    int last_rank;//招收的最后一个的学生的排名
    int num;//收多少人
    vector<int> receive;
};

bool cmp(const Student& o1,const Student&o2)
{
    if(o1.total!=o2.total)
        return o1.total>o2.total;
    else
        return o1.Ge>o2.Ge;
    /*else if(o1.Ge!=o2.Ge)
        return o1.Ge>o2.Ge;
    else return o1.id<o2.id;*/
}

int main()
{
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    vector<School> sch(M);
    vector<Student> stu(N);
    for (int i=0;i<M;++i)
    {
        scanf("%d",&sch[i].num);
    }
    for (int i=0;i<N;++i)
    {
        scanf("%d%d",&stu[i].Ge,&stu[i].Gi);
        for (int j=0;j<K;j++)
            scanf("%d",&stu[i].choice[j]);
        stu[i].total=(stu[i].Ge+stu[i].Gi)/2;
        stu[i].id=i;
    }
    sort(stu.begin(),stu.end(),cmp);
    stu[0].rank=1;
    for (int i=1;i<N;i++)
    {
        if(stu[i].total==stu[i-1].total&&stu[i].Ge==stu[i-1].Ge)
        {
            stu[i].rank=stu[i-1].rank;
        }
        else
        {
            stu[i].rank=i+1;
        }
    }
    for (int i=0;i<N;++i)
    {
        int prefer;
        for (int j=0;j<K;++j)
        {
            prefer=stu[i].choice[j];
            if(sch[prefer].num>0)
            {
                sch[prefer].num--;
                sch[prefer].receive.push_back(stu[i].id);
                sch[prefer].last_rank=stu[i].rank;
                break;
            }
            else if(sch[prefer].last_rank==stu[i].rank)
            {
                sch[prefer].receive.push_back(stu[i].id);
                break;
            }
        }
    }
    for (int i=0;i<M;i++)
    {
        if(sch[i].receive.size()==0)
            printf("\n");
        else
        {
            sort(sch[i].receive.begin(),sch[i].receive.end());
            for (int j=0;j<sch[i].receive.size();++j)
            {
                printf("%d",sch[i].receive[j]);
                if(j!=sch[i].receive.size()-1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}





