//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int w[107];
int tab[1000007];

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		char z;
		cin >> z;
		int x;
		cin >> x;
		if(z == '+') w[i]++;
		else w[i]--;

		if(z == '-' && !tab[x]) w[0]++;

		tab[x] = 1;
	}

	for(int i = 1; i <= n; ++i) w[i] += w[i - 1];
	int wyn = 0;
	for(int i = 0; i <= n; ++i) wyn = max(wyn, w[i]);
	cout << wyn << endl;
	return 0;
}