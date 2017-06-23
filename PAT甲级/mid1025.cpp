//
// @author prime on 2017/6/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Testee
{
    string id;
    int local_num;
    int local_rank;
    int score;
    int total_rank;
};

bool cmp(const Testee& s1, const Testee &s2)
{
    return s1.score==s2.score?s1.id<s2.id:s1.score>s2.score;
}

int main()
{
    int N,K;
    cin>>N;
    vector<Testee> res;
    int total=0;
    for (int i=0;i<N;++i)
    {
        cin>>K;
        total+=K;
        Testee tmp;
        for (int j=0;j<K;++j)
        {
            cin>>tmp.id>>tmp.score;
            res.push_back(tmp);
        }
        /*局部排序*/
        sort(res.end()-K,res.end(),cmp);

        res[total-K].local_rank=1;
        res[total-K].local_num=i+1;

        for (int j=1;j<K;++j)
        {
            res[total-K+j].local_num=i+1;
            if(res[total-K+j].score==res[total-K+j-1].score)
            {
                res[total-K+j].local_rank=res[total-K+j-1].local_rank;
                continue;
            } else
            {
                res[total-K+j].local_rank=j+1;
            }
        }
    }

    sort(res.begin(),res.end(),cmp);

    cout<<total<<endl;
    res[0].total_rank=1;
    for (int i=1;i<res.size();i++)
    {//这一步不能省，起初想法直接输出排名，但是需要考虑可能有多于2个成绩一样的情况，遂两个用例过不去
        if(res[i].score==res[i-1].score)
        {
            res[i].total_rank=res[i-1].total_rank;
        }
        else
           res[i].total_rank=i+1;
    }
    for (auto &e:res)
    {
        cout<<e.id<<" "<<e.total_rank<<" "<<e.local_num<<" "<<e.local_rank<<endl;
    }
    return 0;
}


