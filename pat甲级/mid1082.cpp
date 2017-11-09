//
// @author prime on 2017/7/23.
//
#include <iostream>

using namespace std;

char c[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
char t[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

bool flag=true;//亿位、万位是否为0，true表示是0
bool across=false;//表示是否从亿跨越了万位

void process(int num)
{//四位一处理
    bool flag1,flag2,flag3;//表示千、百、十位是否是0，true表示是0
    flag1=flag2=flag3= true;
    if(num/1000)
    {//千位
        printf("%s %s",t[num/1000],c[2]);
        flag1= false;
    }
    if(num/100%10)
    {//百位
        if(!flag1)//前几位非0
            printf(" ");
        if(!flag&&flag1)
            printf("ling ");
        printf("%s %s",t[num/100%10],c[1]);
        flag2= false;
    }
    if(num/10%10)
    {//十位
        if(!flag2||!flag1)//前几位非0
            printf(" ");
        if((!flag1||!flag)&&flag2)
            printf("ling ");
        printf("%s %s",t[num/10%10],c[0]);
        flag3= false;
    }
    if(num%10)
    {//个位
        if(!flag1||!flag2||!flag3)//前几位非零
            printf(" ");
        if((!flag1||!flag2||!flag)&&flag3)
            printf("ling ");
        printf("%s",t[num%10]);
    }
}

int main()
{
    int a;
    scanf("%d",&a);
    if(a<0)
    {
        printf("Fu ");
        a=-a;
    }
    if(a==0)
        printf("ling");
    if(a>99999999)
    {
        if(a%100000000<=9999)
            across=true;
        printf("%s %s",t[a/100000000],c[4]);
        a%=100000000;
        flag= false;//亿位有效
    }
    if(a>9999)
    {
        if(!flag)
            printf(" ");
        int num=a/10000;
        process(num);
        printf(" %s",c[3]);
        a%=10000;
        flag=false;
    }
    if(across)
        printf(" ling");
    if(a>0)
    {
        if(!flag)
            printf(" ");
        process(a);
    }
    return 0;
}



