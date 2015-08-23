//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;
typedef unsigned long long int llu;
typedef long long ll;
string smallest(string s)
{
    if(s.size()%2==1)
        return s;
    string s1=smallest(s.substr(0,s.size()/2));
    string s2=smallest(s.substr(s.size()/2,s.size()));
    if(s1<s2) return s1+s2;
    else return s2+s1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    string A,B;
    cin>>A>>B;
    if(A.size()!=B.size())
    {
        puts("NO");
        return 0;
    }
    A=smallest(A);
    B=smallest(B);
    if(A==B)
        puts("YES");
        else puts("NO");
    return 0;
}
