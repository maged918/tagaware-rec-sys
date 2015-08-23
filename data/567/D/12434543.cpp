//Language: GNU C++


#define _CRT_SECURE_NO_WARNINGS
#define mp make_pair
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <time.h>
#include <string>
#include <vector>
#include <math.h>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
set <pii> s;
int calc(int x,int y,int a)
{
	return int((y - x+2) / (a + 1));
}
int main()
{
	int n, a, k, m, sum = 0;
	cin >> n >> k >> a;
	cin >> m;
	int x;
	s.insert(mp(n, 1));
	sum = calc(1, n, a);
	for (int i = 0; i < m; i++)
	{
		int newk1 = 0, newk2 = 0;
		cin >> x;
		int l = (s.lower_bound(mp(x, -1)))->second, r = (s.lower_bound(mp(x, -1)))->first;
		if (x > l)
			newk1 = calc(l, x - 1, a);
		if (x < r)
			newk2 = calc(x + 1, r, a);
		sum -= calc(l, r, a);
		sum += newk1 + newk2;
		if (sum < k)
		{
			cout << i + 1 << endl;
			return 0;
		}
		s.erase(s.lower_bound(mp(x, -1)));
		if (x > l)
			s.insert(mp(x - 1, l));
		if (x < r)
			s.insert(mp(r, x + 1));
	}
	cout << -1 << endl;
	return 0;
}