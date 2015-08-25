//Language: GNU C++


#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll n,m;
	cin >> n >> m;
	ll kanan = n-m;
	ll kiri = m-1;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (kanan > kiri) {
		cout << m+1 << endl;
	} else {
		cout << m-1 << endl;
	}
}