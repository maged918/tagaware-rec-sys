//Language: GNU C++11


#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <cassert>
#include <cstring>
#include <bitset>
#include <list>
#ifdef _HOME
#include <intrin.h>
#define __builtin_popcount __popcnt
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
int NUICHE;
#define eprintf(...) NUICHE = 228
#endif

//#define MULTITEST
#define long long long
#define prev _prev
#define rank _rank

using namespace std;

const int maxn = 2e6;
int q, h;

void precalc()
{
	
}

int solve()
{
	scanf("%d%d", &h, &q);
	long cur_l = 1ll << (h - 1), cur_r = (1ll << h) - 1;
	vector<pair<long, long>> bad;
	while (q--)
	{
		int i, ans;
		long l, r;
		scanf("%d%I64d%I64d%d", &i, &l, &r, &ans);
		for (i; i < h; i++)
			l <<= 1, r = (r << 1) + 1;
		if (ans == 1)
		{
			if (cur_l > r || cur_r < l)
				return printf("Game cheated!"), 0;
			cur_l = max(l, cur_l);
			cur_r = min(r, cur_r);
		}
		else
			bad.push_back(make_pair(l, r));
	}
	sort(bad.begin(), bad.end());
	long r = cur_l - 1, ans = -1;
	for (auto it = bad.begin(); it != bad.end(); it++)
	{
		if (it->first > cur_r)
			break;
		if (it->second <= r)
			continue;
		if (it->first - r > 2 || (it->first - r == 2 && ans != -1))
			return printf("Data not sufficient!"), 0;
		if (it->first - r == 2)
			ans = r + 1;
		r = it->second;
		if (r > cur_r && ans == -1)
			return printf("Game cheated!"), 0;
	}
	if (ans == -1)
	{
		if (cur_r - r == 1)
			printf("%I64d", cur_r);
		else if (cur_r - r < 1)
			printf("Game cheated!");
		else
			printf("Data not sufficient!");
	}
	else
	{
		if (cur_r - r > 1 || (cur_r - r == 1 && ans != cur_r))
			printf("Data not sufficient!");
		else
			printf("%I64d", ans);
	}

	return 0;
}

int main()
{
#ifdef _HOME
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	freopen("debug.txt", "wt", stderr);
#endif

	precalc();
	int t;
#ifdef MULTITEST
	scanf("%d", &t);
#else
	t = 1;
#endif
	while (t--)
		solve();

	return 0;
}