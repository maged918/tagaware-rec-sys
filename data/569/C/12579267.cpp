//Language: GNU C++


#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 1000*1000*10


bool is_prime[MAX_N];

int prime_prefix[MAX_N];
int palind_prefix[MAX_N];

float p,q;

void extract_primes() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;
	for(int i = 2; i <= MAX_N; i++) {
		if(is_prime[i])
			for(int j = 2; j*i <= MAX_N; j++)
				is_prime[i*j] = false;
	}
}

bool is_palind(int num) {
	int n = num;
	int sum = 0;
	while(n > 0) {
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	return sum == num;
}

int main() {
	cin >> p >> q;
	float a = p/q;
	memset(prime_prefix, 0, sizeof(prime_prefix));
	memset(palind_prefix, 0, sizeof(palind_prefix));
	extract_primes();
	for(int i = 1; i <= MAX_N; i++) {
		prime_prefix[i] = prime_prefix[i-1] + (is_prime[i] ? 1 : 0);
		palind_prefix[i] = palind_prefix[i-1] + (is_palind(i) ? 1 : 0);
	}
	for(int i = MAX_N; i >= 1; i--) {
		if(prime_prefix[i] <= a * palind_prefix[i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "Palindromic tree is better than splay tree" << endl;
	return 0;
}
