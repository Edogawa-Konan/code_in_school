//
// @author prime on 2017/6/7.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,b;
    scanf("%d %d",&N,&b);
    vector<int> res;
    if(N==0)
    {
        printf("Yes\n0");
        return 0;
    }
    while(N!=0)
    {
        res.push_back(N%b);
        N/=b;
    }
    vector<int>::iterator it1=res.begin(),it2=res.end()-1;
    int flag=true;
    while(it1<it2)
    {
        if(*(it1++)!=*(it2--))
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        printf("Yes\n");

    } else
    {
        printf("No\n");
    }
    for (int i=res.size()-1;i>0;i--)
    {
        printf("%d ",res[i]);
    }
    printf("%d",res[0]);
    return 0;
}





