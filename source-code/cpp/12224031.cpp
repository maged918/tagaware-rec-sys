//Language: GNU C++


#include<bits/stdc++.h>
#define For(i,i1,i2) for(int i=i1;i<i2;i++)
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define V vector<int>
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define CLR(x) memset(x,0,sizeof(x));
using namespace std;
ll dp[3000];
ll fac[1000001],infac[1000001];
ll power(ll a,ll b){
    a=a%MOD;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	ll tmp=power(a,b/2);
	if(b&1)
		return (((tmp*tmp)%MOD)*a)%MOD;
	else
		return (tmp*tmp)%MOD;
}
void cal_fac(){
    fac[0]=1;infac[0]=1;
    For(i,1,1000001){
        fac[i]=(fac[i-1]*i)%MOD;
        infac[i]=power(fac[i],MOD-2);
    }
}
ll nCr(int n,int r){
    if(n<=0  or r<0)
        return 0;
    if(r<0||n<r)
        return 0;
    return (((infac[r]*infac[n-r])%MOD)*fac[n])%MOD;
}
pii arr[3000];
bool comp(pii a,pii b){
    return (a.F==b.F)?a.S<b.S:a.F<b.F;
}
int main(){
    ios::sync_with_stdio(false);
    cal_fac();
    int n,h,w;
    cin>>h>>w>>n;
    For(i,0,n){
        cin>>arr[i].F>>arr[i].S;
        arr[i].F--;arr[i].S--;
    }
    arr[n].F=h-1;arr[n].S=w-1;
    sort(arr,arr+n,comp);
    For(i,0,n+1){
        dp[i]=nCr(arr[i].F+arr[i].S,arr[i].F);
        For(j,0,i){
            if(arr[i].S>=arr[j].S)
            dp[i]=(dp[i]-((dp[j]*nCr(arr[i].F-arr[j].F+arr[i].S-arr[j].S,arr[i].S-arr[j].S))%MOD)+MOD)%MOD;
        }
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n];
}
