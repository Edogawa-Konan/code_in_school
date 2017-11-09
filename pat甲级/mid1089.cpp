//
// @author prime on 2017/7/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int> s(N),p(N);
    for (int i=0;i<N;++i)
        scanf("%d",&s[i]);
    for (int i=0;i<N;++i)
        scanf("%d",&p[i]);
    int point;
    for (point=0;point<N-1&&p[point]<=p[point+1];point++);//point是最后一个有序元素的下标,必须是<=，题目中没说每个数字都不同！！！
    int i;
    point+=1;
    for (i=point;i<N&&p[i]==s[i];i++);
    if(i==N)
    {//如果point之后的元素和原始序列一样，表明是插入排序。
        printf("Insertion Sort\n");
        sort(p.begin(),p.begin()+point+1);//只要在有序的序列上多加一个元素排序即可。
    }
    else
    {
        printf("Merge Sort\n");
        bool flag= true;
        int k=1;
        while(flag)
        {
            flag=false;
            for (i=0;i<N;++i)
            {//需要先找到当前运行到归并排序的第几次,k表示几几归并
                if(s[i]!=p[i])
                    flag= true;
            }
            k*=2;
            for(auto it=s.begin();it<s.end();it+=k)
            {
                if(it+k<=s.end())
                    sort(it,it+k);
                else//把不足k个的最后几个排序
                    sort(it,s.end());
            }
        }
        p=s;
    }
    for(i=0;i<N;++i)
    {
        printf("%d",p[i]);
        if(i!=N-1)
            printf(" ");
    }
    return 0;
}



