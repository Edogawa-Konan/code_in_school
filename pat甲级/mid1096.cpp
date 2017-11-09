//
// @author prime on 2017/7/27.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int n=sqrt(N);
    for (int len=12;len>=1;len--)//2的31次方介于12阶乘与13的阶乘之间，故最长序列不超过12，先试长的再试短的
        for (int start=2;start<=n;start++)//2到根号N开始试
        {
            long res=1;
            for (int i=start;i-start<len;i++)
            {
                res*=i;
            }
            if(N%res==0)
            {
                cout<<len<<"\n";
                for(int i=start;i-start<len;i++)
                {
                    cout<<i;
                    if(i!=len+start-1)
                        cout<<"*";
                }
                return 0;
            }
        }
    cout<<"1\n"<<N;//素数
    return 0;
}
