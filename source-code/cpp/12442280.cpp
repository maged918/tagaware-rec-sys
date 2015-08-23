//Language: GNU C++11


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t,s,q,c=1;
    cin>>t>>s>>q;
    while(t>s*q)
    {
        c++;
        s=s*q;
    }
    cout<<c;
    return 0;
}