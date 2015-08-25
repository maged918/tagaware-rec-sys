//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

#define F first
#define S second
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define INF 2000000000

typedef long long ll;

using namespace std;
int n, a[111111], d, ans, m = 100001, kol[111111], w[111111];
bool bad;
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		int x;
		int l, r = 0;
		bool good = 1;
		while(a[i] > 0){
			x = a[i];
			l = r;
			if(good)
			while(x < m){
				kol[x]++;
		    	w[x] += l++;
		    	x <<= 1;
			}
			else
				kol[x]++, w[x] += r;
			if(a[i] & 1)
				good = 1;
			else
				good = 0;
			a[i] >>= 1;
			r++;
		}
	}
	ans = INF;
	for(int i = 1; i < m; i++)
	if(kol[i] == n)
		ans = min(w[i], ans);	
	cout << ans;
	return 0;
}
