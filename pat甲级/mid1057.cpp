//
// @author prime on 2017/6/27.
//

#include <iostream>
#include <deque>
#include <map>
using namespace std;


map<int,int> dict;
deque<int> stack;

void get_median()
{
    int index=(stack.size()+1)/2;
    int count=0;
    for (auto &e:dict)
    {
        count+=e.second;
        if(count>=index)
        {
            cout<<e.first<<"\n";
            break;
        }
    }
}

int main()
{
    int N;
    char op[15];
    scanf("%d",&N);
    for (int i=0;i<N;++i)
    {
        scanf("%s",op);
        if(op[1]=='o')
        {
            if(stack.empty())
                cout<<"Invalid\n";
            else
            {
                if(dict[stack.back()]==1)
                    dict.erase(stack.back());
                else
                    dict[stack.back()]--;
                cout<<stack.back()<<"\n";
                stack.pop_back();
            }
        } else if(op[1]=='e')
        {
            get_median();
        } else if(op[1]=='u')
        {
            int num;
            scanf("%d",&num);
            stack.push_back(num);
            if(dict.find(num)==dict.end())
            {
                dict[num]=1;
            }
            else
                dict[num]++;
        }
    }
    return 0;
}


