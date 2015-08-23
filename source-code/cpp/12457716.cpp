//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>

#pragma comment(linker, "/STACK:36777216")
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i >= _b; --i)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,0,(n)-1)
#define VI vector <int>
#define ll long long
#define sqr(x) ((x)*(x))

int ddx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ddy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

using namespace std;

#define MOD 1000000007
#define R2 500000004
#define R3 333333336
#define INF 1000000000
#define EPS 1e-6
#define PI 3.1415926535897932384626433832795028841971
#define MAX 100100
using namespace std;


int a[MAX];
int c[MAX];
VI r[MAX];


int main()
{
	int T, S, Q;
	cin >> T >> S >> Q;
	int cur = 0;
	int dwn = 0;
	int ans = 1;
	while (cur != T)
	{
		cur++; dwn++;
		if (dwn > 1)S++;
		if (dwn == Q)dwn -= Q;
		if (cur > S)
			ans++, cur = 1;
	}
	cout << ans << endl;
	
}