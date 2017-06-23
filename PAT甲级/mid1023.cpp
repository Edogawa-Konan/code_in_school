//
// @author prime on 2017/6/11.
//
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int set[10];
    fill(set,set+10,0);
    string num;
    cin>>num;
    int res[num.size()+1];
    fill(res,res+num.size()+1,0);
    for (int i=num.size()-1;i>=0;i--)
    {
        num[i]-='0';
        set[num[i]]++;
        num[i]*=2;

        res[i+1]+=num[i];

        if(num[i]>9)
        {
            res[i]+=num[i]/10;
            res[i+1]%=10;
        }
    }
    //cout<<"length="<<num.size()<<endl;
    for (int i=0;i<num.size()+1;++i)
    {
        if(i==0&&res[i]==0)
            continue;
        if(set[res[i]]>0)
            set[res[i]]--;
        else
        {
            printf("No\n");
            goto NO;
        }
    }
    printf("Yes\n");
    NO:
    for (int i=0;i<num.size()+1;++i)
    {
        if(i==0&&res[i]==0)
        {
            continue;
        }
        printf("%d",res[i]);
    }
    return 0;
}

