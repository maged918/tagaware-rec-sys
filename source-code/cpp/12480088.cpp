//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define ll long long
#define ld long double
#define sqr(x) ((x) * (x))
#define mp make_pair
#define endl "\n"
#define TASKNAME ""

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const ll infll = (ll)1e18;
const ld eps = 1e-9;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(1e5 + 1, 0);
	vector<bool> c(1e5 + 1, 0);
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		b[a[i]]++;
	}
	queue<int> q;
	for (int i = 1; i <= maxx; i++) {
		if (b[i] == 0)
			q.push(i);
	}
	int t = maxx + 1;
	for (int i = 0; i < n; i++) {
		if (!c[a[i]]) {
			c[a[i]] = 1;
			continue;
		}
		if (b[a[i]] > 1) {
			if (q.size() > 0) {
				a[i] = q.front();
				q.pop();
				b[a[i]]--;
			}
			else {
				a[i] = t++;
				b[a[i]]--;
			}
		}
	}
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++)
		v[i] = mp(a[i], i);
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
		return a.first > b.first;
	});
	int j = 0;
	while (!q.empty() && j < v.size()) {
		if (v[j].first < q.front()) {
			j++;
			continue;
		}
		v[j++].first = q.front();
		q.pop();
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});
	for (int i = 0; i < n; i++)
		cout << v[i].first << " ";
} 

int main() {
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif
	
	solve();

#ifdef __DEBUG__
	fprintf(stderr, "\nTime: %Lf\n", ((clock() - start) / (ld)CLOCKS_PER_SEC));
#endif
	return 0;
}