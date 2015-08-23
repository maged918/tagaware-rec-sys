//Language: GNU C++


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

int n, m;
int T[100000 + 8], S[100000 + 8];


void bfs(int x) {
	
	queue<pii> Q;
	bool mark[100000 + 8];
	
	memset(mark, 0, sizeof mark);
	mark[x] = 1;
	
	Q.push(mp(x, 0));
	while(!Q.empty()) {
		int x = Q.front().first, y = Q.front().second;
		T[x]++; S[x] += y;
		Q.pop();
		
		if (x == 0) continue;
		if (x * 2 < 100000 + 8 && !mark[x * 2]) {
			mark[x * 2] = 1;
			Q.push(mp(x * 2, y + 1));
		}
		if (!mark[x / 2]) {
			mark[x / 2] = 1;
			Q.push(mp(x / 2, y + 1));
		}
		
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		bfs(m);
	}

	int r = 1000000000 + 8;
	for (int i = 0; i < 100000 + 8; i++) if (T[i] == n) r = min(r, S[i]);
	cout << r << endl;
	
	return 0;
}