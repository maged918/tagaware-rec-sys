//Language: GNU C++11


#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <iomanip>

#define ld long double
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define y0 _y0
#define y1 _y1

using namespace std;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
    return x * x;
}

int dp[2][505][505];
string a[505];
const int mod = 1e9 + 7;

int main()
{   
    int n, m;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int len = n + m - 1;
    int half = len / 2 + (len & 1);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (len & 1) {
                if (len / 2 == i + j)
                    dp[1][i][i] = 1;
            }
            else {
                if (len / 2 == i + j + 1) {
                    if (i < n - 1 && a[i + 1][j] == a[i][j])
                        dp[1][i][i + 1] = 1;
                    
                    if (j < m - 1 && a[i][j + 1] == a[i][j]) {
                        dp[1][i][i] = 1; 
                    }
                }
            }
        }
    
    int dx[] = {0, 1};
    int dy[] = {1, 0};
    
    for (int clen = 1; clen < half; clen++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (dp[clen & 1][i][j] > 0) {
                    int i1 = i,
                        j1 = half - clen - i,
                        i2 = j,
                        j2 = m - 1 - (half - clen - (n - i2 - 1));
                        
                    for (int l1 = 0; l1 < 2; l1++)
                        for (int l2 = 0; l2 < 2; l2++) {
                            if (i1 - dx[l1] >= 0 && j1 - dy[l1] >= 0 && i2 + dx[l2] < n && j2 + dy[l2] < m) {
                                if (a[i1 - dx[l1]][j1 - dy[l1]] == a[i2 + dx[l2]][j2 + dy[l2]]) {
                                    dp[(clen & 1) ^ 1][i1 - dx[l1]][i2 + dx[l2]] += dp[clen & 1][i][j];
                                    if (dp[(clen & 1) ^ 1][i1 - dx[l1]][i2 + dx[l2]] >= mod)
                                        dp[(clen & 1) ^ 1][i1 - dx[l1]][i2 + dx[l2]] -= mod;
                                }
                            }
                        }
                    
                    dp[clen & 1][i][j] = 0; 
                }
            }
    }   
    
    cout << dp[half & 1][0][n - 1];
    
    return 0;   
}