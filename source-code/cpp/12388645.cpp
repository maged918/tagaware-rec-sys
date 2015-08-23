//Language: GNU C++11


/*************************************************************************
    > File Name: A.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月06日 星期四 20时40分33秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);

int Arr[100010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &Arr[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int mins, maxs;
		if (i == 1) {
			mins = Arr[2] - Arr[1];
			maxs = Arr[n] - Arr[1];
		}
		else if (i == n) {
			mins = Arr[n] - Arr[n - 1];
			maxs = Arr[n] - Arr[1];
		}
		else {
			mins = min(Arr[i] - Arr[i - 1], Arr[i + 1] - Arr[i]);
			maxs = max(Arr[i] - Arr[1], Arr[n] - Arr[i]);
		}
		printf("%d %d\n", mins, maxs);
	} 
	return 0;
}