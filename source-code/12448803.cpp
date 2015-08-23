//Language: GNU C++


#include <iostream>
using namespace std;

int main() {
	long long T, S, q;
	cin >> T >> S >> q;

	int ans = 1;
	long long cur = S * q;
	while (cur < T) {
		ans++;
		cur *= q;
	}

	cout << ans << endl;
	return 0;
}