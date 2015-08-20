//Language: MS C++



#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <set>
#include <ctime>
#include <cmath>
#include <assert.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a; i<(int)n; i++)
#define per(i,n,a) for (int i=n; i>=a; i--)
#define hk push_back
#define pk pop_back
#define mp make_pair
#define PI 3.141592653589793
#define clr(a) memset(a, 0, sizeof(a))
#define clr1(a) memset(a, -1, sizeof(a))
typedef vector<int> VI;
typedef vector< pair<int, int> > VIP;
typedef vector< pair<int, pair<int, double> > > VIPP;
typedef vector<string> VS;
typedef vector <double> VD;
typedef vector <bool> VB;
typedef long long ll;
#define MAX_V 1000
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
    ll res = 1; a %= mod; for (; b; b >>= 1){ if (b & 1)res = res*a%mod; a = a*a%mod; }return res;
}

int n, m;
char board[501][501];
ll dp[2][501][501];

int main()
{
    scanf("%d%d", &n, &m);
//  cin >> n >> m;
    rep(i, 0, n) {
        scanf("%s", board[i]);
//      rep(j, 0, m) {
//          cin >> board[i][j];
//      }
    }
    int repNum = (n + m - 2) / 2;
    bool b = false;
    if (board[0][0] == board[n - 1][m - 1]) dp[b][0][m - 1] = 1;
    rep(j, 1, repNum + 1) {
        b = !b;
        clr(dp[b]);

        int y = min(n, j + 1);
        while (y--) {
            int x = j - y;
            if (x >= m) break;


//          int minX1 = min(x, m - 1 - j);
//          int y1 = n - (minX1 - m + 1 + j);
            int y1 = n;
            rep(x1, m - 1 - j, m) {
                y1--;
                if (y1 < 0 || y1 < y) break;
                if (x1 < 0 || x1 < x) continue;
                if (board[y][x] == board[y1][x1]) {
                    if (y - 1 >= 0) {
                        if (x1 + 1 < m) dp[b][x][x1] += dp[!b][x][x1 + 1];
                        dp[b][x][x1] += dp[!b][x][x1];
                    }
                    if (x - 1 >= 0) {
                        if (x1 + 1 < m) dp[b][x][x1] += dp[!b][x - 1][x1 + 1];
                        dp[b][x][x1] += dp[!b][x - 1][x1];
                    }
                    dp[b][x][x1] %= mod;
                }
            }
        }
    }

    int ret = 0;
    rep(i, 0, repNum + 1) {
        int y = repNum - i, x = i;
        if (x >= m || y < 0) break;
        if (y >= n) continue;

        int l = max(n, m);
        rep(j, 0, l) ret = (ret + dp[b][x][j]) % mod;
    }

    printf("%d", ret);
//  cout << ret << endl;
 
    return 0;
}