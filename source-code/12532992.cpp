//Language: GNU C++


#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <complex>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <sstream>
#include <iterator>

using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 500 + 3;
const ll MOD = 1e9 + 7;

char s[MAXN][MAXN];
ll dp[2][MAXN * 2][MAXN * 2];
pii pt[MAXN * 2];
int id[MAXN][MAXN];

ll add(ll a, ll b){
    return (a + b) % MOD;
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
    }
    if(s[0][0] != s[n - 1][m - 1]){
        printf("0"); return;
    }
    dp[0][0][0] = 1;
    int l = 0, r = n + m - 2;
    int top = 0;
    for(int i = 0; i < n; i++){
        pt[top++] = mp(i, 0);
    }
    for(int i = 1; i < m; i++){
        pt[top++] = mp(n - 1, i);
    }
    for(int i = 0; i < top; i++){
        int x = pt[i].first, y = pt[i].second;
        for(int j = 0; x >= 0 && y < m ; j++){
            id[x][y] = j;
            x--;
            y++;
        }
    }
    for(int i = 0; l + 1 <= r - 1; i ^= 1, l++, r--){
        memset(dp[i ^ 1], 0, sizeof(dp[i ^ 1]));
        for(int x = 0;; x++){
            int fx = pt[l].first - x;
            int fy = pt[l].second + x;
            if(fx < 0 || fy >= m) break;
            for(int y = 0; ; y++){
                int sx = pt[r].first - y;
                int sy = pt[r].second + y;
                if(sx < 0 || sy >= m) break;
                if(!dp[i][x][y]) continue;
                if(fx + 1 < n && sx - 1 >= 0 && s[fx + 1][fy] == s[sx - 1][sy]){
                    dp[i ^ 1][id[fx + 1][fy]][id[sx - 1][sy]] = add(dp[i ^ 1][id[fx + 1][fy]][id[sx - 1][sy]],
                                                                    dp[i][x][y]);
                }
                if(fx + 1 < n && sy - 1 >= 0 && s[fx + 1][fy] == s[sx][sy - 1]){
                    dp[i ^ 1][id[fx + 1][fy]][id[sx][sy - 1]] = add(dp[i ^ 1][id[fx + 1][fy]][id[sx][sy - 1]],
                                                                    dp[i][x][y]);
                }
                if(fy + 1 < m && sx - 1 >= 0 && s[fx][fy + 1] == s[sx - 1][sy]){
                    dp[i ^ 1][id[fx][fy + 1]][id[sx - 1][sy]] = add(dp[i ^ 1][id[fx][fy + 1]][id[sx - 1][sy]],
                                                                    dp[i][x][y]);
                }
                if(fy + 1 < m && sy - 1 >= 0 && s[fx][fy + 1] == s[sx][sy - 1]){
                    dp[i ^ 1][id[fx][fy + 1]][id[sx][sy - 1]] = add(dp[i ^ 1][id[fx][fy + 1]][id[sx][sy - 1]],
                                                                    dp[i][x][y]);
                }
            }
        }
    }
    ll ans = 0;
    if(l == r){
        int x = pt[l].first;
        int y = pt[l].second;
        for(int i = 0; x >= 0 && y < m ; i++){
            ans = add(ans, dp[l & 1][i][i]);
            x--; y++;
        }
    }
    else{
        int x = pt[l].first, y = pt[l].second;
        for(int i = 0; x >= 0 && y < m; i++){
            if(x + 1 < n && s[x][y] == s[x + 1][y]){
                ans = add(ans, dp[l & 1][i][id[x + 1][y]]);
            }
            if(y + 1 < m && s[x][y] == s[x][y + 1]){
                ans = add(ans, dp[l & 1][i][id[x][y + 1]]);
            }
            x--; y++;
        }
    }
    cout << ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}
