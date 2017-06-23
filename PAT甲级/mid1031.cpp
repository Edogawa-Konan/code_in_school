//
// @author prime on 2017/6/16.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string input;
    cin>>input;
    int N=input.size();
    int n1=0,n3;
    for (int n2=3;n2<=N;n2++)
    {
        if((N-n2+2)%2==0&&(N-n2+2)/2>n1&&(N-n2+2)/2<=n2)
            n1=(N-n2+2)/2;
    }
    n3=n1;
    int n2=N+2-n1-n3;
    char out[n1][n2];
    memset(out,' ', sizeof(out));
    for (int i=0;i<n1;i++)
    {
        out[i][0]=input[i];
    }
    for (int i=0,j=n1-1;i<n2;++i,j++)
        out[n1-1][i]=input[j];
    for (int i=0,j=N-1;i<n3;++i,--j)
    {
        out[i][n2-1]=input[j];
    }

    for (int i=0;i<n1;++i)
    {
        for (int j=0;j<n2;j++)
            cout<<out[i][j];
        cout<<endl;
    }
    return 0;
}

