//Language: GNU C++


#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define REP(_i,_j,_k) for(int _i = _j; _i < _k ; _i++)
#define REPS(_i,_j,_k) for(int _i = _j; _i <= _k ; _i++)
#define REPD(_i,_j,_k) for(int _i = _k ; _i >= _j ; _i--)
#define line puts("")
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MOD 1000000007
using namespace std;

int n, m, move;
char st[505][505];
int dp[505][505][251];

int ngedp(int px1, int px2, int rem){
	int py1 = (move - rem - px1);
	int py2 =  m - 1 + (n - 1 - px2 - move + rem);
	if(px1 < 0 || px1 >= n || py1 < 0 || py1 >= m || px2 < 0 || px2 >= n || py2 < 0 || py2 >= m) return 0;
	int& ans = dp[px1][px2][rem];
	if(px1 > px2 || py1 > py2) return ans = 0;
	if(st[px1][py1] != st[px2][py2]) return ans = 0;
	if(px1 == px2 && py1 == py2 && st[px1][py1] == st[px2][py2])	return ans = 1;
	if((abs(px1 - px2) == 1 && (py1 == py2)) || (abs(py1 - py2) == 1 && (px1 == px2)))return ans = 1;
	if(ans == -1){
		ans = 0;
		ans = (ans + ngedp(px1, px2, rem - 1)) % MOD;
		ans = (ans + ngedp(px1 + 1, px2, rem - 1)) % MOD;
		ans = (ans + ngedp(px1, px2 - 1, rem - 1)) % MOD;
		ans = (ans + ngedp(px1 + 1, px2 - 1, rem - 1)) % MOD;
	}
	return ans;
}

int main(){
	scanf("%d %d", &n, &m);
	REP(i,0,n){
		scanf("%s", st[i]);
	}
	memset(dp, -1, sizeof dp);
	move = (m + n - 1);
	if(move % 2) move++;
	move /= 2;
	printf("%d\n", ngedp(0, n - 1, move));
}
