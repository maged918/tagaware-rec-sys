//Language: GNU C++


#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iterator>
#include<iostream>
#include<list>
#include<map>
#include<memory>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<utility>
#include<bitset>
#define ll long long
const ll P=1000000007;
using namespace std;

int h,w,n;
pair<int,int> b[2001];
ll f[200001],dp[2001];

ll pow(ll x,ll y){
    ll ans=1,t=x;
    while(y>0)
    {  if(y&1) ans=ans*t%P;
       t=t*t%P;
       y=y>>1;
    }
    return ans;
}

ll cal(int x,int y){
    return f[x+y]*pow(f[x]*f[y]%P,P-2)%P;
}

int main(){
    int i,j;
    f[0]=1;
    for(i=1;i<=200000;i++) f[i]=f[i-1]*i%P;
    
    scanf("%d%d%d",&h,&w,&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&b[i].first,&b[i].second);
    b[n]=make_pair(h,w);
    sort(b,b+n+1);
    for(i=0;i<=n;i++)
    {   dp[i]=cal(b[i].first-1,b[i].second-1);
        
        for(j=0;j<i;j++)
            if(b[j].first<=b[i].first && b[j].second<=b[i].second)
               dp[i]=(dp[i]-dp[j]*cal(b[i].first-b[j].first,b[i].second-b[j].second)%P+P)%P;               
    }
    printf("%d\n",dp[n]);
    //system("pause");
    return 0;
}
