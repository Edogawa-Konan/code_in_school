//
// @author prime on 2017/6/18.
//

#include <iostream>

using namespace std;

int main()
{
    string male,female;
    int m_score=101,f_score=-1;
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;++i)
    {
        string name,sex,id;
        int score;
        cin>>name>>sex>>id>>score;
        if(sex=="F")
        {
            if(score>f_score)
            {
                f_score=score;
                female=name+" "+id;
            }
        }
        else
        {
            if(score<m_score)
            {
                m_score=score;
                male=name+" "+id;
            }
        }
    }
    if(f_score!=-1&&m_score!=101)
    {
        cout<<female<<"\n"<<male<<"\n"<<f_score-m_score;
    }
    else if(f_score!=-1)
    {
        cout<<female<<"\n";
        cout<<"Absent\n";
        cout<<"NA";
    }
    else if(m_score!=101)
    {
        cout<<"Absent\n"<<male<<"\nNA";
    }
    return 0;
}


