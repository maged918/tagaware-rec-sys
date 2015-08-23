//Language: GNU C++11


#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool notPal[10000001];
vector<int> primes, pals;

void backtr(int len, int pos, int v) {
	if(pos == (len + 1) / 2) {
		int start = 0, base = 1;
		if(len % 2 == 1) {
			start++;
			base *= 10;
		}
		for(; start < pos; start++) {
			int toAdd = v / base % 10;
			v = v * 10 + toAdd;
			base *= 100;
		}
		pals.push_back(v);
		return;
	}

	int digit = 0;
	if(pos == 0) digit++;
	for(; digit < 10; digit++) backtr(len, pos + 1, v * 10 + digit);
}

int main(void) {
	notPal[0] = notPal[1] = true;
	for(int i = 2; i <= 10000000; i++) {
		if(notPal[i]) continue;
		primes.push_back(i);
		for(int j = i * 2; j <= 10000000; j += i) notPal[j] = true;
	}

	for(int len = 1; len <= 7; len++) {
		backtr(len, 0, 0);
	}
	sort(pals.begin(), pals.end());

	long long p, q;
	cin >> p >> q;
/*
	int s = 0, e = 10000001, ans = -1;
	while(s < e) {
		int mid = (s + e) / 2;
		long long prn = upper_bound(primes.begin(), primes.end(), mid)  - primes.begin();
		long long paln = upper_bound(pals.begin(), pals.end(), mid) - pals.begin();
		if(prn * q <= paln * p) {
			ans = mid;
			s = mid + 1;
		} else e = mid;
	}

	int base = ans;
	for(int i = 0; i < 1000; i++) {
		int mid = base + i;*/
	int ans = -1;
	for(int mid = 10000000; mid >= 1; mid--) {
		long long prn = upper_bound(primes.begin(), primes.end(), mid)  - primes.begin();
		long long paln = upper_bound(pals.begin(), pals.end(), mid) - pals.begin();
		if(prn * q <= paln * p) {
			ans = mid;
			break;
		}
	}


	if(ans == -1) cout << "Palindromic tree is better than splay tree";
	cout << ans;
	return 0;
}