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

char a[200001], b[200001];

bool eq(int x1, int y1, int x2, int y2)
{
	bool res = true;
	for (int i = x1; i < y1 && res; ++i)
		res &= (a[i] == b[i - x1 + x2]);

	if (res)
	{
		return true;
	}
	else
	{
		if ((y1 - x1) % 2 == 1)
		{
			return false;
		}
		int ha = x1 + (y1 - x1) / 2;
		int hb = x2 + (y2 - x2) / 2;

		if (eq(x1, ha, x2, hb) && eq(ha, y1, hb, y2))
			return 1;
		if (eq(x1, ha, hb, y2) && eq(ha, y1, x2, hb))
			return 1;

		return 0;
	}
}

void solve()
{
	scanf("%s\n%s\n", &a, &b);
	int size = strlen(a);

	if (eq(0, size, 0, size))
		puts("YES");
	else
		puts("NO");
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

	//ios_base::sync_with_stdio(false);
	solve();

	return 0;
}
#endif