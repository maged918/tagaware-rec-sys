//Language: GNU C++11


#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;
int main() {
    long long n,m,x=0;
    cin>>n>>m;
    if(n-m<=m-1) { x=m-1; }
    else { x=m+1; }
    if(n==m && n==1 && m==1) x=1;
    if(m>n) {
        x=n; }
    if(m<1) { x=1; }
    cout<<x;
}
