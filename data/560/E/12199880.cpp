//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

long long fac[500009]={1};
long long arr[2][2009],n,mod=1e9+7,h,w;
long long dp[2009];

long long fp(long long b,long long p)
{
    if(p==1)
        return b;
    if(p%2)
        return (b*fp(b,p-1))%mod;
    return fp((b*b)%mod,p/2);
}

long long bt(int i)
{
    if(dp[i]!=-1)
        return dp[i];
    long long sum=(fac[h-arr[0][i]+w-arr[1][i]]*fp((fac[h-arr[0][i]]*fac[w-arr[1][i]])%mod,mod-2))%mod;
    for(int f=0;f<n;f++)
        if(arr[0][f]>=arr[0][i]&&arr[1][f]>=arr[1][i]&&f!=i)
            sum=(sum-((fac[arr[0][f]-arr[0][i]+arr[1][f]-arr[1][i]]*fp((fac[arr[0][f]-arr[0][i]]*fac[arr[1][f]-arr[1][i]])%mod,mod-2))%mod)*bt(f)+mod)%mod;
    return dp[i]=sum;
}

int main()
{
    memset(dp,-1,sizeof dp);
    for(int f=1;f<500009;f++)
        fac[f]=(fac[f-1]*f)%mod;
    cin>>h>>w>>n;
    for(int f=0;f<n;f++)
        cin>>arr[0][f]>>arr[1][f];
    long long sum=(fac[h+w-2]*fp((fac[h-1]*fac[w-1])%mod,mod-2))%mod;
    for(int f=0;f<n;f++)
        sum=(sum-((fac[arr[0][f]-1+arr[1][f]-1]*fp((fac[arr[0][f]-1]*fac[arr[1][f]-1])%mod,mod-2))%mod)*bt(f)+mod)%mod;
    cout<<(sum+mod)%mod<<endl;
}
