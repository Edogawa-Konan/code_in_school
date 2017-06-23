//
// @author prime on 2017/6/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string id;
    string name;
    int score;
};

bool cmp_id(const Student& o1, const Student& o2)
{
    return o1.id<o2.id;
}

bool cmp_name(const Student& o1,const Student&o2)
{
    //return o1.name!=o2.name?o1.name<o2.name:o1.id<o2.id;
    return o1.name<=o2.name;
}

bool cmp_score(const Student&o1,const Student&o2)
{
    //return o1.score!=o2.score?o1.score<o2.score:o1.id<o2.id;
    return o1.score<=o2.score;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,C;
    cin>>N>>C;
    vector<Student> s(N);
    for (int i=0;i<N;i++)
    {
        cin>>s[i].id>>s[i].name>>s[i].score;
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
        cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].score<<endl;
    }
    return 0;
}


