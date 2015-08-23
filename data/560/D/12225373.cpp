//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
string prefix(string s)
{
    if(s.size()%2)  return s;
    string s1=prefix(s.substr(0,s.size()/2));
    string s2=prefix(s.substr(s.size()/2));
    if(s1<s2)   return s1+s2;
    else    return s2+s1;
}
int main()
{
    string a,b;
    ios_base::sync_with_stdio(false);
    cin>>a>>b;
    a=prefix(a);
    b=prefix(b);
    if(a==b)    cout<<"YES";
    else    cout<<"NO";
    return 0;
}