//Language: GNU C++11


#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
ll M = 200001;
ll mod = 1000000007;
vector<ll> fuck(M);
vector<ll> unfuck(M);

int modPow(ll a, ll b) {
	ll res;
	if(b == 0) {
		res = 1;
	} else {
		ll tmp = modPow(a, b/2);
		ll tmpp = (tmp*tmp)%mod;
		res = (b%2 == 1 ? a*tmpp : tmpp);
		res %= mod;
	}
	return res;
}

int ckn(ll k, ll n) {
	ll res, num, denum;
	num = fuck[n];
	denum = (unfuck[k]*unfuck[n-k])%mod;
	res = num*denum;
	return res%mod;
}

int main() {
	fuck[0] = 1;
	unfuck[0] = 1;
	for( int i = 1; i < M; ++i) {
		ll tmp = fuck[i-1]*i;
		fuck[i] = tmp % mod;	
		unfuck[i] = modPow(fuck[i], mod - 2);		
	}

	ll h, w, n;
	cin >> h >> w >> n;
	vector<pair<ll, ll>> blacks(n);
	for( int i = 0; i < n; ++i){
		cin >> blacks[i].first >> blacks[i].second;
		blacks[i].first--;
		blacks[i].second--;
	}
	
	sort(blacks.begin(), blacks.end());
	vector<ll> nums(n);
	


	for( int i = 0; i < nums.size(); ++i) {
		nums[i] = ckn(blacks[i].first, blacks[i].first + blacks[i].second);
		for(int j = 0; j < i; ++j) {
			if(blacks[j].second <= blacks[i].second){
				nums[i] -= nums[j]*ckn(blacks[i].first - blacks[j].first, blacks[i].first + blacks[i].second - blacks[j].first - blacks[j].second);
				nums[i] %= mod;
			}
		}
	}

	ll res = ckn(h - 1, h + w - 2);
	for( int i = 0; i < blacks.size(); ++i) {
		res -= nums[i]*ckn(h-1 - blacks[i].first, h+w-2 - blacks[i].first - blacks[i].second);
		res %= mod;
	}
	
	cout << (res + mod)%mod << "\n";
	return 0;
}
