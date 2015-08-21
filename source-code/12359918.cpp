//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <climits>
#include <map>
#include <iterator>
#include <queue>
#include <cstring>
#define mp make_pair
#define pb push_back
#define nfor(i, x, y) for (int i = x; i < y; i++)
#define si(n) scanf("%d", &n)
#define spii(n) scanf("%d%d", &n.first, &n.second)
#define sii(n, m) scanf("%d%d", &n, &m)
#define pi(n) printf("%d", n)
#define sl(n) scanf("%I64d", &n)
#define pl(n) printf("%I64d", n)
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

const long long mod = 1000000007;
const int maxn = 100000;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector <pii> vpii;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("photo.in", "r", stdin);
	//freopen("photo.out", "w", stdout);
#endif
	int n; si(n);
	mii a;
	int ans = 0;
	nfor(i, 0, n)
	{
		char t;
		int tt;
		cin >> t >> tt;
		if (t == '+') a[tt]++;
		else if (a[tt]) a[tt] = 0;
		else ans++;
		int nans = 0;
		for (auto it : a)
		{
			if (it.second) nans++;
		}
		ans = max(ans, nans);
	}
	pi(ans);
	return 0;
}