//
// @author prime on 2017/6/5.
//

#include <iostream>
#include <cmath>

using namespace std;

long long sum(const string&number,long long radix);
void process(string & input);
void binarysearch(long long a,const string &b);
void search(long long a,const string & b);
int find_largest(const string& b);

int main()
{
    string n1,n2;
    int tag,radix;
    cin>>n1>>n2;
    scanf("%d %d",&tag,&radix);
    process(n1);
    process(n2);
    long long a;
    string b;
    if(tag==1)
    {
        a=sum(n1,radix);
        b=n2;
    } else{
        a=sum(n2,radix);
        b=n1;
    }
    search(a,b);
    return 0;
}


void binarysearch(long long a,const string & b)
{
    long long low=find_largest(b),mid,tmp;
    long long high=max(low,a)+1;
    while(low<=high)
    {
        mid=(low+high)/2;
        tmp=sum(b,mid);
        if(tmp<a)
        {
            low=mid+1;
        }
        else if(tmp>a)
        {
            high=mid-1;
        }
        else
        {
            printf("%lld",mid);
            return ;
        }
    }
    printf("Impossible");
}

void search(long long a,const string & b)
{
    long long tmp=-1,r=find_largest(b);
    while(tmp!=a)
    {
        if(tmp>a)
        {
            printf("Impossible");
            return;
        }
        tmp=sum(b,r);
        r++;
    }
    printf("%lld",r-1);
}

long long sum(const string &number,long long radix)
{
    long long res=0;
    int bit=0;
    for (long long i=number.size()-1;i>=0;--i)
    {
        res+=pow(double(radix),double(bit))*number[i];
        bit++;
    }
    return res;
}

void process(string & input)
{
    for (long long i =input.size()-1;i>=0;--i)
    {
        if(input[i]>='0'&&input[i]<='9')
        {
            input[i]-='0';
        } else
        {
            input[i]=input[i]-'a'+(char)10;
        }
    }
}

int find_largest(const string& b)
{//找出最小进制
    int largest=-1;
    for (auto it=b.cbegin();it!=b.cend();it++)
    {
        if(*it>largest)
            largest=*it;
    }
    return largest+1;//最大数为largest，最小进制为largest+1.比如110，进制最小是2
}