//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

string s[500];
int M = 1000000007;
int n, m;
int dp[2][500][500];

inline void add(int& x, int y) {
    x += y;
    if (x >= M) x -= M;
}

bool check(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    else return 1;
}

void solve(int len) {
    for(int y1 = 0; y1 < n; y1++) {
        int x1 = len - y1;
        if (x1 < 0 || x1 >= m) continue;
        for(int y2 = y1; y2 < n; y2++) {
            int x2 = n + m - 2 - len - y2;
            
            if (x2 < 0 || x2 >= m) continue;
            if (s[y1][x1] != s[y2][x2]) continue;
            add(dp[0][y1][y2], dp[1][y1][y2]);
           
            if (check(x1 - 1, y1)) {
                if (check(x2, y2 + 1)) add(dp[0][y1][y2], dp[1][y1][y2 + 1]);
            } 
            if (check(x1, y1 - 1)) {
                //if (y1 == 1 && y2 == 3) cout << "h" << endl;
                if (check(x2, y2 + 1)) add(dp[0][y1][y2], dp[1][y1 - 1][y2 + 1]);
                //if (y1 == 1 && y2 == 3) cout << dp[0][y1][y2] << endl;
                if (check(x2 + 1, y2)) add(dp[0][y1][y2], dp[1][y1 - 1][y2]);
                //if (y1 == 1 && y2 == 3) cout << dp[0][y1][y2] << endl;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[1][i][j] = dp[0][i][j];
            dp[0][i][j] = 0;
        }
    }
    //cout << dp[0][1][3] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    if (s[0][0] != s[n - 1][m - 1]) {
        cout << 0;
        return 0;
    }
    
    dp[1][0][n - 1] = 1;
    
    int len = (n + m - 1) / 2;

    for(int i = 1; i < len; i++) {
        solve(i);
    }
    
    //cout << dp[1][1][3] << endl;
    
    if (((n + m) & 1) == 0)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            add(ans, dp[1][i][i]);
            if (i < n - 1) add(ans, (2 * dp[1][i][i + 1]) % M);
            if (i < n - 2) add(ans, dp[1][i][i + 2]);
        }
        cout << ans;
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            add(ans, dp[1][i][i]);
            if (i < n - 1) add(ans, dp[1][i][i + 1]);
            
        }
            
        cout << ans;
    }
}