//Language: GNU C++11


#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map> 
#include <set>

#define endl "\n"

using namespace std;
typedef long long int lint;

class Combinatorics{
private:
	lint fmax, rmax, mod;
	std::vector<lint> fact, rfact;
	bool bits[64];
	int bits_size;

	lint rev(lint a);
public:
	Combinatorics(lint mod, lint fmax, lint rmax);
	Combinatorics(lint mod, lint maxval);
	Combinatorics(lint mod);

	void fit(lint fmax, lint rmax);
	void fit_if_needed(lint fmax, lint rmax);
	void chmod(lint new_mod);

	lint C(lint n, lint k);
	lint factorial(lint n);
	lint P(lint n);
	lint A(lint n, lint k);
};

void Combinatorics::chmod(lint nmod){
	mod = nmod;
	lint k = mod - 2;
	bits_size = 0;
	while (k > 0){
		bits[bits_size] = k % 2;
		bits_size++;
		k /= 2;
	}
	lint f = fmax, r = rmax;
	fmax = -1;
	rmax = -1;
	fit(f, r);
}

lint Combinatorics::rev(lint a){
	lint r = 1;
	for (int i = bits_size - 1; i >= 0; i--){
		r = r*r %mod;
		if (bits[i])
			r = r*a %mod;
	}
	return r;
}

Combinatorics::Combinatorics(lint mod, lint fmax, lint rmax) :fmax(fmax), rmax(rmax){
	chmod(mod);
}

Combinatorics::Combinatorics(lint mod, lint maxval) : Combinatorics(mod, maxval, maxval){}

Combinatorics::Combinatorics(lint mod) : Combinatorics(mod, 0, 0){}

void Combinatorics::fit(lint f, lint r){
	(this->fact).resize(f + 1);
	(this->rfact).resize(r + 1);
	if (f < r) f = r;
	if (f > fmax){
		this->fact[0] = 1;
		for (int i = std::max(fmax, 1LL); i <= f; i++){
			this->fact[i] = this->fact[i - 1] * i%mod;
		}
	}
	if (r > rmax){
		this->rfact[0] = 1;
		for (int i = std::max(rmax, 1LL); i <= r; i++){
			this->rfact[i] = rev(this->fact[i]);
		}
	}
	fmax = f;
	rmax = r;
}

void Combinatorics::fit_if_needed(lint f, lint r){
	if (f > fmax || r > rmax) fit(f, r);
}

lint Combinatorics::factorial(lint n){
	fit_if_needed(n, 0);
	return fact[n];
}

lint Combinatorics::P(lint n){
	fit_if_needed(n, 0);
	return fact[n];
}

lint Combinatorics::A(lint n, lint k){
	fit_if_needed(n, n - k);
	return fact[n] * rfact[n - k] % mod;
}

lint Combinatorics::C(lint n, lint k){
	fit_if_needed(n, std::max(k, n - k));
	return fact[n] * rfact[n - k] % mod *  rfact[k] % mod;
}

lint bell[4001];
lint eq[4001];
lint mod = 1000000007;

void task(){
	Combinatorics c(mod);
	int n;
	cin >> n;
	bell[0] = 1;
	eq[0] = 1;
	for (int i = 0; i < n+1; i++){
		bell[i + 1] = 0;
		for (int j = 0; j <= i; j++){
			bell[i + 1] = (bell[i+1] + (bell[j] * c.C(i, j)) % mod)%mod;
		}
	}
	cout << ((bell[n + 1] - bell[n])>0 ? (bell[n + 1] - bell[n]) : (bell[n + 1] - bell[n] + 10*mod)) % mod;
}

int main(){

#ifdef ILEASILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#else
	ios_base::sync_with_stdio(false);
#endif

	task();

#ifdef ILEASILE
	clock_t finish = clock();
	cout <<"\n\n=============\n" <<(finish - start) / (double)CLOCKS_PER_SEC;
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}