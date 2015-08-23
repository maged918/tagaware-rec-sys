//Language: GNU C++


#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
 
#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
 
#define st first
#define nd second
#define mp make_pair
#define pb push_back
 
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
 
const int oo = 0x3f3f3f3f;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vii;

int cnt[1000100];
int l[1000100], r[1000100];
int main() {
	int n;
	sc(n);
	cl(cnt,0);
	cl(l,-1);
	int m = 0;
	rp(i,n) {
		int a;
		sc(a);
		if (l[a] == -1) l[a] = i;
		r[a] = i;
		cnt[a]++;
		m = max(m, cnt[a]);
	}
	int best = 100000000;
	int id = 0;
	fr(i,1,1000001) {
		if (cnt[i] == m) {
			if (r[i]-l[i] < best) {
				best = r[i] - l[i];
				id = i;
			}
		}
	}
	printf("%d %d\n", l[id]+1, r[id]+1);
}