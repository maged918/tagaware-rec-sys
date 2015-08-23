//Language: GNU C++


#include <iostream>
using namespace std;

#define mod 1000000007

long long int fact[4010], inv[4010], invfact[4010];

void init(){
	fact[0]= 1;
	for (int i=1; i<4010; i++){
		fact[i]= i*fact[i-1];
		
		fact[i]= fact[i]%mod;
		fact[i]+=mod;
		fact[i]= fact[i]%mod;
	}
	inv[1]= 1;
	for (int i=2; i<4010; i++){
		inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
		
	}
	invfact[0]= 1;
	for (int i=1; i<4010; i++){
		invfact[i]= invfact[i-1]*inv[i] % mod;
		invfact[i]+=mod;
		invfact[i]= invfact[i]%mod;
	
	}
}

int nCr(int n,int k){
	return ((invfact[n-k]*invfact[k]%mod)*fact[n]%mod)%mod;
}

long long int count[4050];

int main() {
	// your code goes here
	int n;
	cin>>n;
	count[0]= 1;
	count[1]= 1;
	init();
	long long int sum= 0;
	for (int i=0; i<=4010; i++){
		sum= 0;
		for (int j=0; j<=i; j++){
			sum+=nCr(i, j)*count[j];
			sum= sum%mod;
		}
		count[i+1]= sum;
	}
	long long int ans= 0;
	for (int i=0; i<n; i++){
		ans+=nCr(n, i)*count[i];
		ans= ans%mod;
	}
	ans= (ans+mod)%mod;

	cout<<ans<<endl;

	return 0;
}