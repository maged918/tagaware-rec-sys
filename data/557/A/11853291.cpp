//Language: GNU C++


//BISMILLAHIR RAHMANIR RAHIM


#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<time.h>
#include<map>
#include<iostream>
#include<vector>
#define pii pair<int,int>
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define SETINF(a) memset(a,126,sizeof a)
#define LLI long long int
#define ULL unsigned long long
#define PI acos(-1.0)
#define EPS 1e-9
#define inf 1<<30
#define f first
#define s second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define countbit(x) __builtin_popcount(x)
#define lpi(i,a,b) for(int i=a;i<b;i++)
#define lpd(i,a,b) for(int i=a;i>b;i--)
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)

//#define MAX(a) (*max_element(all(a)))
//#define MIN(a) (*min_element(all(a)))

using namespace std;

template< class T > inline T sq(T a) { return a * a; }
template< class T, class X > inline T _pow(T a,X y) {T z=1; repi(i,1,y){z*=a;} return z; }
template< class T > inline T gcd(T a, T b) {while(b) b ^= a ^= b ^= a %= b;return a;}
template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template< class T > inline T extended(T a,T b,T &x,T &y) {a=abs(a);b=abs(b); T g,x1,y1; if(!b) {x=1;y=0;g=a; return g;} g=extended(b,a%b,x1,y1); x=y1; y=x1-(a/b)*y1; return g;}
template< class T, class X > inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0); }
template< class T, class X > inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template< class T, class X > inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i))); }
template< class T, class X > inline T togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

template< class T,class X, class Y > inline T bigmod(T n,X m,Y mod){ULL ret=1, a = n%mod ; while(m){ if(m&1)ret=(ret*a)%mod; m>>=1; a=(a*a)%mod; }ret%=mod;return (T)ret;}
template< class T, class Y > inline T modinv(T n,Y mod) {return bigmod(n,mod-2,mod);}
template< class T > inline T _gcd(T a,T b) {a=_abs(a);b=_abs(b); if(!b) return a; return _gcd(b,a%b);}

///-----------------//-----------------//



int main()
{
     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

      //    freopen("output.txt","w",stdout);
     //    freopen("input.txt","r",stdin);

int n;
int mini[4];
int maxi[4];
int ans[4];
LLI tot=0;
cin>>n;
for (int i=0;i<3;i++)
    {cin>>mini[i]>>maxi[i];
    tot+=ans[i]=maxi[i];
    }

if(tot==n)
{
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
}
else
{int t=2;
    while(tot!=n)
    {
        if(ans[t]>mini[t])
            ans[t]--,tot--;
        else
            t--;
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
}







return 0;
}
