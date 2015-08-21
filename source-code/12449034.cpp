//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cassert>
#include <map>
 
#define ll long long int
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
 
#define f first
#define s second
 
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
 
#define pb push_back
#define pob pop_back
#define mp make_pair
 
#define max_size 200005
#define max_capacity INT_MAX
#define max_string_size 1000
#define max_node_size 340
#define max_power 26
#define max_sieve_size 1300005
#define max_log 17
#define MOD 1000000007L
 
using namespace std;

/* This function calculates primes upto the given max_sieve_size. */
ll sieve[max_sieve_size];
ll suf[max_sieve_size];
vector <ll> primes;
void calc_sieve()
{
	sieve[0] = sieve[1] = -1;
	suf[0] = suf[1] = 0;
 
	for(int i=2; i<max_sieve_size; i++)
	{
		suf[i] = suf[i-1];
		if(sieve[i]==0)
		{
			suf[i]++;
			primes.pb(i);
			for(ll j=i; j<max_sieve_size; j=j+i)
			{
				sieve[j]++;
			}
		}
	}
}

ll suf2[max_sieve_size];
void palindromic() {
	suf2[0] = 0;
	for(int i=1; i<=1300000; i++) {

		suf2[i] = suf2[i-1];
		ll j = 0, k = i;
		while(k){
			j = j*10 + k%10;
			k = k/10;
		}

		if(j==i)
			suf2[i]++;
	}
}

int main() {
	calc_sieve();
	palindromic();

	ll p, q;
	cin>>p>>q;
	ll ans = 0;
	for(int i=0; i<=1300000; i++) {
		if(q*suf[i]<=p*suf2[i])
			ans = i;
	}

	cout<<ans<<endl;

	return 0;
}