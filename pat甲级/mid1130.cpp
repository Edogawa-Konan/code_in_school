//
// @author prime on 2017/8/13.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int left,right;
    string val;
};

vector<Node> s;
int Root;

string DFS(int root)
{//通过DFS把表达式存储到根节点的val里
    if(root==-1)
        return "";
    if(s[root].right!=-1)
    {//如果没有右孩子说明不是叶子节点，可以只有一个左孩子！
        s[root].val=DFS(s[root].left)+s[root].val+DFS(s[root].right);
        if(root!=Root)
        {
            s[root].val="("+s[root].val+")";
        }
    }
    return s[root].val;
}

int main()
{
    int N;
    cin>>N;
    s.resize(N+1);
    vector<bool> exist(N+1,false);//没出现的下标就是根节点
    for (int i=1;i<=N;++i)
    {
        cin>>s[i].val>>s[i].left>>s[i].right;
        if(s[i].left!=-1)
            exist[s[i].left]=true;
        if(s[i].right!=-1)
            exist[s[i].right]=true;
    }
    for (Root=1;Root<=N&&exist[Root];++Root);
    DFS(Root);
    cout<<s[Root].val;
    return 0;
}


