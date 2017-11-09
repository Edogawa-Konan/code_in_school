//
// @author prime on 2017/6/28.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N;
    char a[10000],b[10000];
    scanf("%d",&N);
    scanf("%s %s",a,b);
    int dig_a=strlen(a),dig_b=strlen(b);//a和b小数点的位置
    int start_a=0,start_b=0;//a和b中第一个非0数字所在位置
    for (int i=0;i<strlen(a);i++)
    {
        if(a[i]=='.')
        {
            dig_a=i;
            break;
        }
    }
    for (int j=0;j<strlen(b);j++)
        if(b[j]=='.')
        {
            dig_b=j;
            break;
        }
    while(a[start_a]=='0'||a[start_a]=='.') start_a++;
    while(b[start_b]=='0'||b[start_b]=='.') start_b++;
    int exponent_a,exponent_b;
    if(start_a==strlen(a))
        exponent_a=0;
    else
    {
        if(dig_a>=start_a)
            exponent_a=dig_a-start_a;
        else
            exponent_a=dig_a-start_a+1;
    }
    if(start_b==strlen(b))
        exponent_b=0;
    else
    {
        if(dig_b>=start_b)
            exponent_b=dig_b-start_b;
        else
            exponent_b=dig_b-start_b+1;
    }
    char res_a[101],res_b[101];
    int count_a=0,count_b=0;
    while(count_a<N)
    {
        if(start_a<strlen(a)&&a[start_a]!='.')
            res_a[count_a++]=a[start_a];
        else if(start_a>=strlen(a))
            res_a[count_a++]='0';
        start_a++;
    }
    while(count_b<N)
    {
        if(start_b<strlen(b)&&b[start_b]!='.')
            res_b[count_b++]=b[start_b];
        else if(start_b>=strlen(b))
            res_b[count_b++]='0';
        start_b++;
    }
    if(strcmp(res_a,res_b)==0&&exponent_a==exponent_b)
    {
        printf("YES 0.%s*10^%d",res_a,exponent_a);
    }
    else
    {
        printf("NO 0.%s*10^%d 0.%s*10^%d",res_a,exponent_a,res_b,exponent_b);
    }
    return 0;
}



