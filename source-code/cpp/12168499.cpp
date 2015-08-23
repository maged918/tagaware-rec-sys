//Language: GNU C++11


#include <bits/stdc++.h>
#define  FOR(i,x,n) for(int i=x;i<n;i++)
#define rFOR(i,x,n) for(int i=x;i>n;i--)
#define SZ(x) (int)x.size()
typedef long long ll;
const int SIZE=1e5+5;
using namespace std;

int a[3],b[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);

    FOR(i,0,3) 
        cin>>a[i]>>b[i];
    
    if( 
        (a[1]+a[2]<=a[0] & max(b[1],b[2])<=b[0]) |
        (b[1]+b[2]<=b[0] & max(a[1],a[2])<=a[0]) |
        (a[1]+a[2]<=b[0] & max(b[1],b[2])<=a[0]) |
        (b[1]+b[2]<=a[0] & max(a[1],a[2])<=b[0]) |
        (a[1]+b[2]<=a[0] & max(b[1],a[2])<=b[0]) |
        (a[1]+b[2]<=b[0] & max(b[1],a[2])<=a[0]) |
        (b[1]+a[2]<=a[0] & max(a[1],b[2])<=b[0]) |
        (b[1]+a[2]<=b[0] & max(a[1],b[2])<=a[0])
      )
        cout<<"YES";
      else
        cout<<"NO";
}