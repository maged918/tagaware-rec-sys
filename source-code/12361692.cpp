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
int n, x, ans, cur;
char s;
bool ok[1000100];
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s >> x;
		if(s == '-'){
		 	if(!ok[x])
		 		ans++, cur++;
		 	ok[x] = 0;
		 	cur--;
		}
		else{
			ok[x] = 1;
			cur++;
			ans = max(ans, cur);
		}
	}
	cout << ans;
	return 0;
}
