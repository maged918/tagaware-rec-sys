//Language: GNU C++11


#if 1
#include <iostream>
#include <cstdio>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <locale>

using namespace std;
#define PROBLEM "problem"
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
#define X first 
#define Y second 

const int INF = 1000 * 1000 * 1000;
const LL INF64 = 1LL * INF * INF;
const LL mod = INF + 7;

void solve()
{
	int n;
	cin >> n;

	set<int> a;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}

	if (!a.count(1))
		cout << 1 << endl;
	else
		cout << -1 << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#else
	//freopen(PROBLEM".in", "r", stdin); freopen(PROBLEM".out", "w", stdout);
#endif

	//cout.precision(10);
	//cout.setf(ios_base::fixed);

	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}
#endif