//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define FILENAME ""
#define INF 2000000000
#define ll long long
using namespace std;

int a[6], res, y;

int solve(int x, int k, int k2){
	k = min(k, k2);
	int sum = 0;
	for(int i = 1; i <= k; i++){
		sum += x + x + 1;
		x++;
	}
	y = x;
	return sum;
}

int prev(int x){
	if(x == 0)return 5;
	return x - 1;
}

int next(int x){
	if(x == 5)return 0;
	return x + 1;
}

int main(){

	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);

	int init = 0;

	res += solve(a[init], a[next(init)], a[prev(init)]);
	res += abs(a[next(init)] - a[prev(init)]) * y * 2;
	res += solve(a[next(next(next(init)))], a[next(next(next(next(init))))], a[next(next(init))]);

	printf("%d", res);

	return 0;
}












//
