//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<deque>
#include<set>

using namespace std;

#define i_n(a) scanf("%d",&a)
#define l_n(a) scanf("%I64d",&a)
#define s_n(a) scanf("%s",a)
#define LL long long int
#define pb(a) push_back(a)
#define pp pair<int,int>
#define vv vector<int>
#define vvp vector<pp>
#define i_p(a) printf("%d\n",a)
#define l_p(a) printf("%I64d\n",a)
#define s_p(a) printf("%s",a)
#define pnt(expr) printf(#expr"\n")
#define reset(a,val) memset(a,val,sizeof(a))
#define m1 1000000000
#define mod 1000000007
#define pr(cn,x) ((cn).find(x)!=(cn).end())
#define tr(cn,it) for(typeof((cn).begin()) it=(cn).begin();it!=(cn).end();it++)
#define read() freopen("fraud.in","r",stdin)
#define write() freopen("prem3.txt","w",stdout)
#define ADDMOD(a,b)  (a%mod+b%mod)%mod
#define MULMOD(a,b)  (a%mod*b%mod)%mod


bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
    return p1.first < p2.first;
}

int dp[3][4005];
int main()
{

   int n;
   i_n(n);
   dp[1][1]=1;
   for(int i=2;i<=n;i++)
   {
       for(int j=1;j<=i;j++)
       {
           int curr;
           if(i%2==0)
            curr=0;
           else
            curr=1;
           if(j==1)
           {
                dp[curr][j]=dp[curr^1][i-1]%mod;
                continue;
           }
           dp[curr][j]=(dp[curr^1][j-1]%mod+dp[curr][j-1]%mod)%mod;
       }
   }
   int ans=0;
   for(int i=1;i<=n;i++)
       ans=(ans%mod+dp[n&1][i]%mod)%mod;

   i_p(ans%mod);
 return 0;
}
