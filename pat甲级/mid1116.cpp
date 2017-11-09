//
// @author prime on 2017/8/4.
//

#include <iostream>
#include <vector>

using namespace std;

vector<bool> table(10010,true);

struct Node
{
    //int id;
    int ward;//0-1-2
    bool valid;//是否有效
    bool first;//输出一次置为false
};

string w[]={"Mystery Award","Minion","Chocolate"};

int main()
{
    for (int i=2;i*i<10010;i++)
        for (int j=2;i*j<10010;j++)
            table[i*j]= false;
    int N;
    scanf("%d",&N);
    vector<Node> dict(10000);
    for (int i=1;i<=N;i++)
    {
        int id;
        scanf("%d",&id);
        dict[id].valid=true;
        dict[id].first=true;
        if(i==1)
            dict[id].ward=0;
         else if(table[i])
        {//排名素数
            dict[id].ward=1;
        } else
            dict[id].ward=2;
    }
    int M;
    scanf("%d",&M);
    for (int i=1;i<=M;i++)
    {
        int id;
        scanf("%d",&id);
        printf("%04d: ",id);
        if(dict[id].valid)
        {
            if(dict[id].first)
            {

                cout<<w[dict[id].ward]<<endl;
                dict[id].first=false;
            } else
                cout<<"Checked\n";
        } else
            cout<<"Are you kidding?\n";

    }
    return 0;
}


