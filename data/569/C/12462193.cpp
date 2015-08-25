//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>

#define ffi(n) for(int i = 0; i < n; i++)
#define ffj(n) for(int j = 0; j < n; j++)
#define lli long long int

using namespace std;

vector<int> Primes;
vector<int> Palindromes;
int k = 1900000;

void getPrimes(){
	Primes.clear();
	Primes.push_back(2);
	bool flag;
	ffi(k){
		flag = true;
		ffj(Primes.size()){
			if(Primes[j] * Primes[j] > i+3) break;
			if((i+3) % Primes[j] == 0){
				flag =false;
				break;
			}
		}
		if (flag) Primes.push_back(i+3);
	}
}

bool isPalin(int n){
	vector<int> dig; 
	dig.clear();
	while(n > 0){
		dig.push_back(n % 10);
		n /= 10;
	}
	ffi(dig.size()) if(dig[i] != dig[dig.size() - i - 1]) return false;
	return true;
}

void getPalindromes(){
	Palindromes.clear();
	ffi(k) if(isPalin(i+1)) Palindromes.push_back(i+1);	
}

int ans(int p, int q){
	int palcnt = 0, pricnt = 0, maxi = 0;
	ffi(k-10000){
		if(Primes[pricnt] == i) pricnt++;
		if(Palindromes[palcnt] == i) palcnt++;
		if((q * pricnt) <= (p * palcnt)) maxi = max(maxi, i);
	}
	return maxi;
}

int main(void){
	getPrimes();
//	ffi(100) cout<<Primes[i]<<" "; cout<<"\n";
	getPalindromes();
//	ffi(100) cout<<Palindromes[i]<<" "; cout<<"\n";
	int p, q;
	cin>>p>>q;
	cout<<ans(p, q);
	return 0;
}
