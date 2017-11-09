//
// @author prime on 2017/6/27.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct People
{
    char name[9];
    int age,worth;
};

void my_search(const vector<People> &p,int age_i,int age_j,int times)
{
    int count=0;
    for (auto& e:p)
    {
        if(count==times)
            break;
        else if(e.age>=age_i&&e.age<=age_j)
        {
            printf("%s %d %d\n",e.name,e.age,e.worth);
            count++;
        } else
            continue;
    }
    if(count==0)
        printf("None\n");
}


bool cmp(const People&o1,const People&o2)
{
    if(o1.worth!=o2.worth)
        return o1.worth>o2.worth;
    else if(o1.age!=o2.age)
        return o1.age<o2.age;
    else
        return strcmp(o1.name,o2.name)<0;
}

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    vector<People> p(N);
    for (int i=0;i<N;++i)
    {
        scanf("%s %d %d",p[i].name,&p[i].age,&p[i].worth);
    }
    sort(p.begin(),p.end(),cmp);
    for (int i=0;i<K;++i)
    {
        int times,age_i,age_j;
        scanf("%d%d%d",&times,&age_i,&age_j);
        printf("Case #%d:\n",i+1);
        my_search(p,age_i,age_j,times);
    }
    return 0;
}


