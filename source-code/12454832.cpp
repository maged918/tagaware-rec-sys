//Language: MS C++


#ifndef EOLIMP
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <algorithm>
#include <functional>
#include <set>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
//#include <cstdio>
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define INF 1000000000
#define NINF -1000000000
#define mod 1000000007LL

using namespace std;

int qpow(int b, int e)
{
	if (e == 0) return 1;
	if (e == 1) return b;
	if (e & 1)
		return (ll(b) * qpow((ll(b) *b) % mod, e >> 1)) % mod;
	else
		return qpow((ll(b) *b) % mod, e >> 1);
}

int C(int n, int k)
{
	ll res = 1;
	if (k > n - k) k = n - k;
	for (int i = k + 1; i <= n; ++i)
		res = (res * i) % mod;
	ll tmp = 1;
	for (int i = 2; i <= n - k; ++i)
		tmp = (tmp * i) % mod;
	tmp = qpow(tmp, mod - 2);
	return (tmp * res) % mod;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//std::ifstream in("input.txt");	std::streambuf *cinbuf = std::cin.rdbuf();	std::cin.rdbuf(in.rdbuf()); 
	//std::ofstream out("output.txt");std::streambuf *coutbuf = std::cout.rdbuf(); std::cout.rdbuf(out.rdbuf());
	//freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<vector<int>> S(n + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; ++i)
	{
		S[i][0] = 0;
		S[0][i] = 0;
		S[i][i] = 1;
	}
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j < i; ++j)
		S[i][j] = (S[i - 1][j - 1] + ll(j) * S[i - 1][j]) % mod;
	ll res = 0;
	for (int i = 0; i < n; ++i)
	{
		ll c = C(n, n - i);
		for (int j = 0; j <= i; ++j)
			res = (res + c * S[i][j])% mod;
	}
	cout << res;
	return 0;
}