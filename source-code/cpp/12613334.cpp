//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,s,q,cnt=1;
    cin>>t>>s>>q;
    while(q*s<t)cnt++,s=q*s;
    cout<<cnt<<endl;
}
