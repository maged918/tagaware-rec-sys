//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,left,right;
    cin>>n>>m;
    left=m-1;
    right =n-m;
    if(n==1)cout<<n<<endl;
    else if(left>=right)cout<<m-1<<endl;
    else cout<<m+1<<endl;
    return 0;
}
