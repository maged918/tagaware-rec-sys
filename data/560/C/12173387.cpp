//Language: GNU C++11


#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<deque>
#include<math.h>
#include<cctype>
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
    int a[10],i,ans=0,k,x;
    rep(i,6)
        cin>>a[i];
    ans+= 2*a[0] + 1;
    k=ans;
    for(i=1;i<min(a[1],a[5]);i++)
    {
        k=k+2;
        ans+= k;
    }
    x= abs(a[5]-a[1]);
    ans+= (k+1)*x;

    k= 2*a[3] + 1;
    ans+=k;
    for(i=1;i<min(a[2],a[4]);i++)
    {
        k+=2;

        ans+= k;}
    cout<<ans;
    return 0;
}
