//Language: GNU C++


#include<iostream>
using namespace std;
#define ll long long
const ll N=4e3+5,mod=1e9+7;
ll fact[N],dfact[N],ans[N];
ll pow(ll a,ll n)
{
	return (n?(pow((a*a)%mod,n/2)*(n%2?a:1))%mod:1);
}
ll c(ll n,ll k)
{
	return (((fact[n]*dfact[k])%mod)*dfact[n-k])%mod;
}
int main()
{
	fact[0]=dfact[0]=1;
	for(ll i=1;i<N;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
        dfact[i]=pow(fact[i],mod-2);
    }
	ans[0]=1;
	for(ll i=1;i<N;i++)
		for(ll k=0;k<i;k++)
			ans[i]=(ans[i]+(c(i-1,k)*ans[k])%mod)%mod;
	ll n,anss=0;
	cin>>n;
	for(ll i=0;i<n;i++)
    {
		ll cnt=c(n,i);
		cnt=(cnt*ans[i])%mod;
		anss=(anss+cnt)%mod;
	}
	cout<<anss<<endl;
}
