//Language: GNU C++


#include<bits/stdc++.h>

#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)

#define MP           make_pair
#define PB           push_back
#define REP(i, n)    for(int i = 0; i < n; i++)
#define INC(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)
#define CLEAR(a)     memset(a, 0, sizeof a)

using namespace std;

typedef long long          LL;
typedef unsigned long long ULL;
typedef vector<int>        VI;
typedef pair<int, int>     II;
typedef vector<II>         VII;

int ncr[4005][4005];
int f[4005];
const int N = 4000;
const int MOD = 1e9+7;
inline int modexp(int a,int b,int c)
{
      if(b==0) return 1;
      if(b==1) return a%c;
      int temp = modexp(a,b/2,c);
      temp = (temp*1LL*temp)%c;
      if(b&1) temp = (temp*1LL*a)%c;
      return temp;
}
void precomp()
{
      ncr[0][0]=1;
      INC(i,1,N)
            ncr[i][0]=1,ncr[i][i]=1;
      INC(i,2,N)
      INC(j,1,i-1)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%MOD;
}
int main()
{
      //cout<<modexp(4564,3242,1000000007)<<endl;;
      precomp();
      int n;
      s(n);
      f[0] = 1;
      f[1] = 0;
      f[2] = 1;
      INC(i,3,N)
      {
            f[i]=1;
            INC(j,2,i-2)
                  f[i] = (f[i] + (ncr[i-1][j]*1LL*f[j])%MOD)%MOD;
      }
      int ans = 0;
      INC(i,1,n)
            ans = (ans + ((modexp(2,i,MOD)-1+MOD)*1LL*((ncr[n][i]*1LL*f[n-i])%MOD))%MOD)%MOD;
      assert(ans>=0);
      printf("%d\n",ans);
      return 0;
}
