//
// @author prime on 2017/7/2.
//


#include <iostream>
#include <algorithm>

using namespace std;

struct People
{
    int id;
    int score[6];//5道题得分情况
    int total_score;
    int perfect_num;//完美通过的题目数量;
    int rank;//最后的排名
    bool valid;
};

bool cmp(const People&o1,const People&o2)
{
    if(o1.total_score!=o2.total_score)
        return o1.total_score>o2.total_score;
    else if(o1.perfect_num!=o2.perfect_num)
        return o1.perfect_num>o2.perfect_num;
    else if(o1.valid!=o2.valid)//必须加上这个，不然最后一个过不去
        return o1.valid>o2.valid;
    else
        return o1.id<o2.id;
}

int main()
{
    int N,K,M;
    scanf("%d%d%d",&N,&K,&M);
    int p[10];//五道题的分值
    for (int i=1;i<=K;++i)
        scanf("%d",&p[i]);
    vector<People> in(N+1);
    for (int i=1;i<=N;++i)
    {
        fill(in[i].score,in[i].score+6,-2);//一开始得分全部是-2
        /*in[i].total_score=0;
        in[i].valid=false;
        in[i].perfect_num=0;*/
    }
    for (int i=0;i<M;++i)
    {
        int id,problem_id,score;
        scanf("%d%d%d",&id,&problem_id,&score);
        if(in[id].score[problem_id]>=score)
            continue;
        else
        {
            in[id].id=id;
            if(score>=0)
            {//这次成绩有效
                in[id].valid=true;//有一个得分为正表示有效
                if(in[id].score[problem_id]>0)
                    in[id].total_score+=score-in[id].score[problem_id];
                else
                    in[id].total_score+=score;
            }
            in[id].score[problem_id]=score;
            if(score==p[problem_id])
            {
                in[id].perfect_num++;
            }
        }
    }
    sort(in.begin()+1,in.end(),cmp);
    in[1].rank=1;
    for (int i=2;i<in.size();++i)
    {
        if(!in[i].valid)
            break;
        if(in[i].total_score==in[i-1].total_score)
            in[i].rank=in[i-1].rank;
        else
            in[i].rank=i;
    }
    for (int k=1;k<in.size();++k)
    {
        if(!in[k].valid)
            break;
        printf("%d %05d %d ",in[k].rank,in[k].id,in[k].total_score);
        for (int i=1;i<=K;++i)
        {
            if(in[k].score[i]>=0)
                printf("%d",in[k].score[i]);
            else if(in[k].score[i]==-1)//-1表示没有通过编译
                printf("0");
            else//等于-2表示从来没提交过
                printf("-");
            if(i!=K)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
