//
// @author prime on 2017/6/8.
//
#include <iostream>
#include <map>
#include <set>


using namespace std;

map<string,set<int>> Title,Author,Keywords,Publisher,Year;

void query(const map<string,set<int>> &s,string &query_str);

int main()
{
    int N,M;
    cin>>N;
    string title,author,keywords,publisher,year;
    int id;
    for (int i=0;i<N;++i)
    {
        cin>>id;
        getchar();//读取换行符
        getline(cin,title);
        Title[title].insert(id);
        getline(cin,author);
        Author[author].insert(id);
        while (cin>>keywords)
        {
            Keywords[keywords].insert(id);
            char c=getchar();//读取字符，提升到int后返回，这样可以容纳EOF等特殊值
            if(c=='\n')
                break;
        }
        /*getline(cin,keywords);
        for (string & e:split(keywords,' '))
        {
            Keywords[e].insert(id);
        }*/
        getline(cin,publisher);
        Publisher[publisher].insert(id);
        getline(cin,year);
        Year[year].insert(id);
    }
    string query_str;
    int num;
    cin>>M;
    for (int i=0;i<M;++i)
    {
        scanf("%d: ",&num);
        getline(cin,query_str);
        cout<<num<<": "<<query_str<<"\n";
        if(num==1)
        {
            query(Title,query_str);
        } else if(num==2)
            query(Author,query_str);
        else if(num==3)
            query(Keywords,query_str);
        else if(num==4)
            query(Publisher,query_str);
        else if(num==5)
            query(Year,query_str);
    }
    return 0;
}

void query(const map<string,set<int>> &s,string &query_str)
{
    map<string,set<int>>::const_iterator it=s.find(query_str);//find返回迭代器，其指向一个pair，pair.first==key
    if(it==s.cend())
    {
        printf("Not Found\n");
    } else
    {
        for (auto &e:it->second)//set可以直接这样遍历，用迭代器也行。基于范围的for循环本质上可以运用于任何拥有begin和end成员的序列
            printf("%07d\n",e);//必须7位，我就艹了！
    }
}


