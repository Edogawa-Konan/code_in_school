#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string input;
    cin>>input;
    int sum=0;
    for (int i = 0; i <input.length(); ++i)
    {
        sum+=input[i]-'0';
    }
    vector<int> output;
    while(sum>0)
    {
        output.push_back(sum%10);
        sum/=10;
    }
    if(output.size()>0)
    {//特殊情况判断
        for (int j = output.size()-1; j>0 ; --j)
            cout<<s[output[j]]<<" ";
        cout<<s[output[0]];
    } else
    {
        cout<<s[0];
    }
    return 0;
}


