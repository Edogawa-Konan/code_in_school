//
// @author prime on 2017/6/3.
//

#include <iostream>
using namespace std;

//int main()
//{
//    int n;
//    cin>>n;
//    int a[n];
//    for (int i = 0; i <n; ++i)
//    {
//        cin>>a[i];
//    }
//    int b[n]={0};//以i为结尾的最大子序列和
//    int max_sum=-1;
//    b[0]=a[0];
//    int begin=0,res_begin=0,res_end=0;
//    bool flag=false;
//    for (int j = 1; j <n; ++j)
//    {
//        if(a[j]>=0)
//            flag=true;
//        if(b[j-1]>0)
//        {
//            b[j]=b[j-1]+a[j];
//        }
//        else
//        {
//            b[j]=a[j];
//            begin=j;
//        }
//        if(b[j]>max_sum)
//        {
//            max_sum=b[j];
//            res_begin=begin;
//            res_end=j;
//        }
//    }
//    if(!flag&&a[0]<0)
//        cout<<0<<" "<<a[0]<<" "<<a[n-1];
//    else
//        cout<<max_sum<<" "<<a[res_begin]<<" "<<a[res_end];
//    return 0;
//}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
    int max_sum=-1,left=0,right=0,tmp=0,tmp_left=0;
    bool all_negative= true;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
            all_negative= false;
        tmp+=a[i];
        if(tmp>max_sum)
        {
            max_sum=tmp;
            left=tmp_left;
            right=i;
        }
        else if(tmp<=0)
        {
            tmp=0;
            tmp_left=i+1;
        }
    }
    if(all_negative)
        cout<<0<<" "<<a[0]<<" "<<a[n-1];
    else
        cout<<max_sum<<" "<<a[left]<<" "<<a[right];
    return 0;
}


