//
// @author prime on 2017/8/5.
//


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int M,N,S;
    scanf("%d%d%d",&M,&N,&S);
    vector<string> s(M+1);
    for (int i=1;i<=M;i++)
        cin>>s[i];
    unordered_map<string,bool> dict;
    if(M<N||M<S)
        printf("Keep going...");
    else
    {
        for (int i=S;i<=M;i+=N)
        {
            while (dict[s[i]])//如果这货拿到奖了就继续往下循环。
                i++;

            if(i>M)//越界及时跳出
                break;
            cout<<s[i]<<endl;
            dict[s[i]]=true;
        }
    }
    return 0;
}


