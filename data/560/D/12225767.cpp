//Language: GNU C++


/*input
abcdxyzt
abcdtzxy
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <cstdio>
#include <bitset>
#include <fstream>

#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vlu;
typedef pair<int, int> pii;

int n;
string s, t;

bool canEqual (string s, string t) {
	int mark[26 + 8];
	memset(mark, 0, sizeof mark);

	for (int i = 0; i < s.length(); i++) mark[s[i] - 'a']++;
	for (int i = 0; i < t.length(); i++) mark[t[i] - 'a']--;

	for (int i = 0; i < 26 + 8; i++)
		if (mark[i] > 0) return false;
	return true;
}

int match(string x, string y) {
	// cout << x << " " << y << endl;
	if (x == y) return true;
	if (x.length() % 2 == 1) return false;
	if (!canEqual(x, y)) return false;

	int len = x.length() / 2;
	bool flag1 = match(x.substr(0, len), y.substr(len, len)) && match(x.substr(len, len), y.substr(0, len));
	if (flag1) return flag1;

	bool flag2 = match(x.substr(0, len), y.substr(0, len)) && match(x.substr(len, len), y.substr(len, len));
	return flag2;
}

int main() {
	cin >> s >> t;
	cout << (match(s, t) ? "YES" : "NO") << endl;
	return 0;
}