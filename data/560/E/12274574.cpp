//Language: GNU C++


#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 1e5 + 10;
const int MAX_N = 2010;
const long MOD = 1000000007L; 
long long fac[2*MAX_SIZE], inv[2*MAX_SIZE], paths[MAX_N];

struct point {
	int x; int y;
};

int h, w, n;

bool compare(const point& a, const point& b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

long long mypow(long long b, long long p) {
	long long res = 1L;
	
	for(; p; p >>= 1, b = b * b % MOD)
        if(p & 1) res = res * b % MOD;
	return res;
}

long long ncr(long long n, long long r)
{
	if(n < r) return 0L;
	return ((fac[n] * inv[r] % MOD) * inv[n-r]) % MOD;
}

void init() {
	fac[0] = 1L; fac[1] = 1L; inv[1] = 1L;
	for(int i=2;i<2*MAX_SIZE;i++) {
		fac[i] = (i%MOD * fac[i-1]%MOD)%MOD;
	}
	inv[1] = 1L;
	inv[0] = 1L;
	for(int i=2;i<2*MAX_SIZE;i++) {
		inv[i] = mypow(fac[i], MOD-2L)%MOD;				
	}
}

point black[MAX_N];
int main() {	
	init();	
	cin >> h >> w >> n;
	for(int i=0;i<n;i++) {		
		cin >> black[i].x >> black[i].y;
	}
	black[n].x = h; black[n].y = w;
	sort(black, black+n+1L, compare);

	for(int i=0;i<=n;i++) {
		paths[i] = ncr(black[i].x-1 + black[i].y-1, black[i].x-1);
		for(int j=0;j<i;j++) {
			paths[i] = (paths[i] + MOD - (paths[j]*ncr(black[i].x-black[j].x + black[i].y-black[j].y, black[i].x-black[j].x))%MOD)%MOD;
		}
	}
	cout << paths[n] << endl;
	return 0;
}