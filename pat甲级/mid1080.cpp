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
    vector<int> quota(M);//各个学校名额
    vector<int> res[M];
    vector<Student> stu(N);
    for (int i=0;i<M;++i)
        scanf("%d",&quota[i]);
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
    int rank=-1,target=-1;//记录上一个人的排名和他选的学校
    for (int i=0;i<N;++i)
    {
        for (int j=0;j<K;j++)
        {
            int prefer=stu[i].choice[j];
            if(quota[prefer]>0)
            {
                rank=stu[i].rank;
                target=prefer;
                quota[prefer]--;
                res[prefer].push_back(stu[i].id);
                break;
            }
            else if(stu[i].rank==rank&&prefer==target)
            {
                res[prefer].push_back(stu[i].id);
                break;
            }
        }
    }
    for (int i=0;i<M;i++)
    {
        if(res[i].size()==0)
            printf("\n");
        else
        {
            sort(res[i].begin(),res[i].end());
            for (int j=0;j<res[i].size();++j)
            {
                printf("%d",res[i][j]);
                if(j!=res[i].size()-1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}



