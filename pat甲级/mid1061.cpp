//
// @author prime on 2017/6/29.
//

#include <iostream>

using namespace std;

int main()
{
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    auto len1=min(a.size(),b.size());
    auto len2=min(c.size(),d.size());
    int res[3];
    int next;
    for (int i=0;i<len1;++i)
    {
        if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
        {
            res[0]=a[i]-'A';//一周内的第几天(0~6)
            next=i;
            break;
        }
    }
    for (int i=next+1;i<len1;i++)
        if(a[i]==b[i]&&(a[i]>='0'&&a[i]<='9'||a[i]>='A'&&a[i]<='N'))
        {
            if(a[i]>='0'&&a[i]<='9')
                res[1]=a[i]-'0';//几点
            else
                res[1]=a[i]-'A'+10;
            break;
        }
    for (int i=0;i<len2;++i)
    {
        if(c[i]==d[i]&&(c[i]>='A'&&c[i]<='Z'||c[i]>='a'&&c[i]<='z'))
        {
            res[2]=i;
            break;
        }
    }
    string week[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cout<<week[res[0]]<<" ";
    printf("%02d:%02d",res[1],res[2]);//日期格式，各占2位
    return 0;
}

