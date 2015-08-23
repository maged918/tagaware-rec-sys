//Language: GNU C++11


// PrimesOrPalindromes.cpp : Defines the entry point for the console application.
//


#include <iostream>

using namespace std;

const long long maxN = 1e7;

long long pi[maxN]; // primes[i] = no of primes no greater than i 
bool check[maxN]; // check[i] = 0 if i is prime; 1 otherwise
long long	rub[maxN]; // rub[i] = no of palindromic number no greater than i

int main()
{
	long long p, q;
	cin >> p >> q;

	// primes
	for (long long i = 2; i < maxN; i++) {
		if (!check[i]) {
			pi[i] = pi[i - 1] + 1;
			for (long long j = 2 * i; j < maxN; j += i)
				check[j] = 1;
		}
		else {
			pi[i] = pi[i - 1];
		}
	}

	// palindromes
	for (long long i = 1; i < maxN; i++) {
		// check if i is palindromic
		long long tmp = i;
		long long rev = 0;
		while (tmp != 0) {
			rev = rev * 10 + tmp % 10;
			tmp /= 10;
		}
		if (rev == i) {
			rub[i] = rub[i - 1] + 1;
		}
		else {
			rub[i] = rub[i - 1];
		}
	}
	/*
	cout << "PRIMES\n";
	for (int i = 0; i < 100; i++) {
		cout << i << " - " << check[i] << " - " << pi[i] << endl;
	}
	cout << endl;
	cout << "PALINDROMES\n";
	for (int i = 0; i < 100; i++) {
		cout << i << " - " << rub[i] << endl;
	}
	*/
	
	for (long long i = maxN-1; i > 0; i--) 
		if (q * pi[i] <= p * rub[i]) {
			cout << i;
			return 0;
		}
	
	cout << "Palindromic tree is better than splay tree";
	
    return 0;
}

