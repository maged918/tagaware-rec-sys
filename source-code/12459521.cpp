//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#define MAXN 1190001

using namespace std;

int p, q;
int prime[MAXN], pal[MAXN];
bool composite[MAXN], ispal[MAXN];

bool checkpal(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		int j = s.length() - i - 1;
		if (s[i] != s[j])
		{
			return false;
		}
	}
	return true;
}

int main()
{
//	freopen ("cf569c.in", "r", stdin);
//	freopen ("cf569c.out", "w", stdout);
	cin >> p >> q;
	composite[1] = true;
	int x;
	for (int i = 2; i < 1180000; i++)
	{
		x = i;
		if (composite[i])
		{
			continue;
		}
		while(x < 1180000)
		{
			x += i;
			composite[x] = true;
		}
	}
//	cerr << prime[0];
	//veri good wan we have checked
	//now time to assign to other arr
	pal[0] = 0;
	for (int i = 1; i < 1180000; i++)
	{
		prime[i] = prime[i - 1];
		pal[i] = pal[i - 1];
		if (!composite[i])
		{
			prime[i]++;
		}
		stringstream ss;
		ss << i;
		string s = ss.str();
		if (checkpal(s))
		{
			pal[i]++;
//			cerr << i << endl;
		}
	}
	//prime[i] * q <= p* pal[i]
//	cout << prime[1999999] - prime[999999];
//	cerr << prime[1999999] << ' ' << pal[1999999] << endl;
	for (int i = 1180000 - 1; i > 0; i--)
	{
//		cerr << prime[2620] * q << ' ' << pal[2620] * p << endl;
		if (prime[i] * q <= pal[i] * p)
		{
			cout << i;
			return 0;
		}
	}

}
