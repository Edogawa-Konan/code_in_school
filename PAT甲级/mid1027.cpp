//
// @author prime on 2017/6/12.
//


#include <iostream>
#include <vector>

using namespace std;

char map[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};

vector<int> convert(int a)
{
    vector<int> res;
    res.push_back(a/13);
    res.push_back(a%13);
    return res;
}


int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    vector<int> A=convert(a),B=convert(b),C=convert(c);
    printf("#%c%c%c%c%c%c",map[A[0]],map[A[1]],map[B[0]],map[B[1]],map[C[0]],map[C[1]]);
    return 0;
}
