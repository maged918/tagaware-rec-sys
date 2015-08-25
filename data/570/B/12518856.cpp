//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m,n; cin>> n>> m; if(n==1) {cout<<"1"; return 0;}
    if(m<=n/2){cout<< m+1; return 0;}
    else{cout<<m-1; return 0;}
}
