//Language: GNU C++


#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <bitset>
#include <ctime>
#include <list>
using namespace std;
#define mp make_pair
#define ull unsigned long long
#define ll long long
#define mod1 (ll)1000000009
#define mod (ll)1000000007
#define inf 1600000016000000000
#define mpi acos(-1.0)
#define M_E (double)2.71828182846
#pragma comment(linker, "/STACK:1000000000")

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("queue.in", "r", stdin);
	//freopen("queue.out", "w", stdout);
	int t, s, q, a, b, c, r = 0;
	cin >> t >> s >> q;
	while (s < t){
		a = s * q;
		if (s * q >= t)
			break;
		++r;
		s = a;
	}
	cout << r + 1 << endl;
	return 0;
}