//Language: GNU C++11


#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ll long long
#define sz(s) int(s.size())
#define ull unsigned long long
#define sc(s) scanf("%d",&s)
#define pr(s) printf("%d ",s)
#define all(s) s.begin(),s.end()
#define only_cin ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

const int MAXN = 1e5 + 256;
const char nxt = '\n';
inline void in (string Q) {Q += ".in";freopen (Q.c_str(), "r", stdin);}
inline void out (string Q) {Q += ".out";freopen (Q.c_str(), "w", stdout);}
inline void open_file (string Q) {in (Q);out (Q);}

string s, k;
bool check (string q, string w) {
	if (q == w) {
		return 1;
	}
	if (sz (q) & 1) {
		return 0;
	}
	int mid = sz (q) >> 1;
	if (check (q.substr (0, mid), w.substr (0, mid)))
		return check (q.substr (mid, mid), w.substr (mid, mid));
	else if (check (q.substr (mid, mid), w.substr (0, mid)))
		return check (q.substr (0, mid), w.substr (mid, mid));
	return 0;
}

int main () {
	#ifdef accepted
		in ("");
	#endif
	only_cin;

	cin >> s >> k;

	if (check (s, k))
		cout << "YES";
	else
		cout << "NO";

    return 0;
}