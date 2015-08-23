//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <cmath>
#include <map>
#define ll long long
#define ull unsigned long long
#define FOR(i, n) for (int i = 0; i < n; i++)
#define si(x) scanf("%d", &x);
using namespace std;

int main()
{
	long long T, S, q;
	cin>>T>>S>>q;
	int ans =1;
	S= S*q;
	while( S<T )
	{	
		S = (S*q);
		ans ++;
	}
	cout<<ans<<"\n";
	return 0;
}
