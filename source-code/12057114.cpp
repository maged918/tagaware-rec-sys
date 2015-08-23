//Language: GNU C++


#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <ctime>
#include <cstring>
#include <sstream>

//#include <unordered_map>

using namespace std;

//types
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<pii> vpii;

// for
#define FI(n) for(int i=0; i<n; i++)
#define FI1(n) for(int i=1; i<=n; i++)
#define FJ(n) for(int j=0; j<n; j++)
#define FJ1(n) for(int j=1; j<=n; j++)
#define FK(n) for(int k=0; k<n; k++)
#define FU(i, n) for (int i=0; i<n; i++)
#define F(i, s, e) for (int i=s; i<=e; i++)

//scanf types
#define SI(x) scanf("%d", &x)
#define SII(x, y) scanf("%d %d", &x, &y)
#define SIII(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define SIIII(x, y, z, t) scanf("%d %d %d %d", &x, &y, &z, &t)
#define SD(x) scanf("%lf", &x)
#define SP(x) scanf("%d %d", &x.first, &x.second)
#define SS(x) scanf("%s", &x)
#define SA(x, n) FI(n) SI(x[i])
#define SAA(x, n, m) FI(n) FJ(m) SI(x[i][j])

#define Tests(t) int t; SI(t); for(int test=1; test<=t; test++)
#define WS(n) int n; while(SI(n) != EOF)

//scanf with def
#define DI(x) int x; SI(x)
#define DII(x, y) int x, y; SII(x, y);
#define DIII(x, y, z) int x, y, z; SIII(x, y, z);
#define DD(x) double x; SD(x)
#define DS(x) string s; cin>>s
#define DA(a, n) int n; SI(n); SA(a, n);
#define DA2(a, n) int n; SI(n); SAA(a, n, n)
#define DAA(a, n, m) int n, m; SII(n, m); SAA(a, n, m)

//input & files
#define FR(x) freopen(x, "rt", stdin)
#define FW(x) freopen(x, "wt", stdout)
#define FRW(x, y) FR(x); FW(y)
#define UNSYNC() ios::sync_with_stdio(false)

//output && db
#define DB(x) cout<<#x<<" = "<<(x)<<" ";
#define DBN(x) cout<<#x<<" = "<<(x)<<"\n";
#define DBA(x, n) {cout<<#x<<" = [ "; FI(n) cout<<x[i]<<((i+1==n)?" ]":", ");}
#define DS(x) {cout<<#x<<" = [ "; int i = 0, n = x.size(); for(auto x:c) { cout<<x[i]<<((i+1==n)?" ]":", "); i++;}}

#define PI(x) printf("%d", x)
#define PIS(x) printf("%d ", x)
#define PIN(x) printf("%d\n", x)
#define PA(x, n) FI(n) if (i+1==n) PIN(x) : PIS(x)
#define PS(x) for (auto it: x) cout<<it<<" "; 

//consts
const int INF = 1 << 30;
const int mod = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932;

//pair
#define x first
#define y second

//functions
double sqr(double x) { return x*x; };
ll sqr(ll x) { return x*x; };
ll sqr(int x) { return x * 1LL * x; };

const int MX = 25;
const int N = 100201;
const int SN = 400;
const int AN = 'z' - 'a' + 1;

struct block {
	int sum[AN];
	int arr[N];
	int srt;
	int st, fn;

	block() {
		srt = 0;
		st = fn = 0;
	}

	void erase(int l, int r, int * rsum) {
		if (l > fn || r < st)
			return;

		if (l <= st && r >= fn) {
			FI(AN) {
				rsum[i] += sum[i];
				if (sum[i]) {
					//DB(i); DBN(sum[i]);
				}
				sum[i] = 0;
			}
			return;
		}

		if (srt) push();

		for (int i = max(l, st); i <= min(r, fn); i++) {
			rsum[arr[i-st]]++;
			sum[arr[i-st]]--;
		}
	}

	void insert(int l, int r, int * rsum, bool rev) {
		if (l > fn || r < st)
			return;

		if (l <= st && r >= fn) {
			int last = fn - st + 1;
			for (int cur = rev ? AN - 1 : 0; last; cur += rev ? -1 : 1) {
				int can = rsum[cur];
				if (can) {
					if (can >= last) {
						rsum[cur] -= last;
						sum[cur] += last;
						last = 0;
					}
					else {
						rsum[cur] -= can;
						sum[cur] += can;
						last -= can;
					}
				}
			}
			
			srt = rev ? -1 : 1;
			return;
		}


		if (srt) push();
		
		int cur = rev ? AN - 1 : 0;
		for (int i = max(l, st); i <= min(r, fn); i++)  {
			while (!rsum[cur])
				cur += rev ? -1 : 1;

			rsum[cur]--;
			sum[cur]++;
			arr[i - st] = cur;
		}
	}
	
	void push() {
		if (srt) {

			bool rev = srt == -1;
			int cur = rev ? AN - 1 : 0;
			int dsum = sum[cur];
			for (int i = st; i <= fn; i++) {
				while (!dsum) {
					cur += rev ? -1 : 1;
					dsum = sum[cur];
				}
				dsum--;
				arr[i-st] = cur;
			}

			srt = 0;
		}

	}

	void write() {
		push();
		for (int i = st; i <= fn; i++)
			putchar(arr[i-st] + 'a');
	}
};

block bs[500];
int sum[35];

int main() {
	//FRW("input.txt", "output.txt");

	DII(n, k);
	string s; cin >> s;

	int cb = 0;
	int cr = 0;
	bs[cb].st = 1;
	FI(n) {
		if (cr == SN) {
			cr = 0;
			cb++;
			bs[cb].st = i + 1;
		}
		bs[cb].arr[cr] = s[i] - 'a';
		bs[cb].sum[s[i] - 'a']++;
		bs[cb].fn = i + 1;
		cr++;
	}
	cb++;

	FI(k) {
		DIII(l, r, k);
		FJ(cb) {
			bs[j].erase(l, r, sum);
		}
		FJ(cb) {
			bs[j].insert(l, r, sum, k == 0);
		//	bs[j].write();
		}
	}


	FJ(cb)
		bs[j].write();

	cout << endl;

	
	cin.get(); cin.get();
	return 0;
}