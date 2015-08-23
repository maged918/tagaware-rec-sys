//Language: GNU C++11


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>
#define LL long long
#define INF 0x7fffffff
using namespace std;

const int MOD = 1e9+7;

LL Bell[4005][4005];

int main() {
	int n;
	scanf("%d", &n);
	Bell[0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		Bell[i][0] = Bell[i - 1][i - 1];
		for(int j = 1; j <= i; j ++) {
			Bell[i][j] = (Bell[i][j - 1] + Bell[i - 1][j - 1]) % MOD;
		}
	}
	printf("%I64d\n", Bell[n][n - 1]);
	return 0;
}
