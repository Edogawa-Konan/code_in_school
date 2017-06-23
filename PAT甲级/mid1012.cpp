//
// @author prime on 2017/6/5.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


class Student
{
public:
    int id;
    int score[4];//0下标代表平均分
    int best;//最好的科目下标
    int rank[4];
};


char course[4]={'A','C','M','E'};
int current;//不能声明成index，我就fuck了
bool cmp(Student s1,Student s2)
{
    return s1.score[current]>s2.score[current];
}

int main()
{
    map<int,int> exist;
    int n,m;
    scanf("%d %d",&n,&m);
    Student s[n];
    for (int i=0;i<n;++i)
    {
        scanf("%d %d %d %d",&s[i].id,&s[i].score[1],&s[i].score[2],&s[i].score[3]);
        s[i].score[0]=(s[i].score[1]+s[i].score[2]+s[i].score[3])/3.0+0.5;//平均数四舍五入
    }
    for(current=0;current<4;++current)
    {
        sort(s,s+n,cmp);
        s[0].rank[current]=1;
        for(int i=1;i<n;++i)
        {
            s[i].rank[current]=i+1;
            if(s[i].score[current]==s[i-1].score[current])
                s[i].rank[current]=s[i-1].rank[current];
        }
    }
    for(int i=0;i<n;++i)
    {
        exist[s[i].id]=i;
        int minx=s[i].rank[0];
        s[i].best=0;
        for(int j=1;j<4;j++)
        {
            if(s[i].rank[j]<minx)
            {
                minx=s[i].rank[j];
                s[i].best=j;
            }
        }
    }/*
    for(auto & e:s)
    {
        printf("%d %d %d %d %d %d %d\n",e.id,e.score[0],e.score[1],e.score[2],e.score[3],course[e.best],e.rank[e.best]);
    }*/
    for(int i=0;i<m;++i)
    {
        int id,k;
        scanf("%d",&id);
        if(exist.find(id)!=exist.end())//map如果没有对应的键值，就会插入键，然后值初始化。用at会抛出异常，算法题不适合。还是用这种方法吧。
        {
            k=exist[id];
            printf("%d %c\n",s[k].rank[s[k].best],course[s[k].best]);

        } else
        {
            printf("N/A\n");
        }
    }
    return 0;
}
