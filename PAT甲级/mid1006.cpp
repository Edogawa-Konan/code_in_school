//
// @author prime on 2017/6/3.
//


#include <iostream>

using namespace std;

int main()
{
    int m;
    cin>>m;
    string first_in_id,last_out_id,first="24:00:00",last="00:00:00";
    string id,in,out;
    for (int i = 0; i <m; ++i)
    {
        cin>>id>>in>>out;
        if(in<first)
        {
            first_in_id=id;
            first=in;
        }
        if(out>last)
        {
            last_out_id=id;
            last=out;
        }
    }
    cout<<first_in_id<<" "<<last_out_id;
    return 0;
}
