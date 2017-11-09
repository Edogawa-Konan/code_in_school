//
// @author prime on 2017/7/27.
//

#include <iostream>
using namespace std;

string low[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13]={"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int s_to_i(const string&v)
{
    for (int k=0;k<13;k++)
    {
        if(high[k]==v)
        {
            return k*13;
        }
        if(low[k]==v)
        {
            return k;
        }
    }
}



int main()
{
    int N;
    cin>>N;
    string input;
    getchar();//读取第一行的换行符
    for (int i=0;i<N;++i)
    {
        getline(cin,input);
        if(isdigit(input[0]))
        {
            int num=stoi(input);
            int L=num%13,H=num/13;
            if(H!=0)
            {
                if(L==0)
                    cout<<high[H]<<"\n";
                else
                    cout<<high[H]<<" "<<low[L]<<"\n";
            }

            else
                cout<<low[L]<<"\n";
        }
        else
        {
            input+=' ';
            int res=0;
            for (int j=0,last=0;j<input.size();j++)
            {
                if(input[j]==' ')
                {
                    string v=input.substr(last,j-last);
                    last=j+1;
                    res+=s_to_i(v);
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}

