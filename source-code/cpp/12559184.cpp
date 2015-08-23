//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x)

#define FOR(i,a,b)      for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b)     for(int i=(int)(b)-1;i>=(int)(a);i--)

#define MOD       1000000007
#define EPS       1E-10

#define PI  acos(-1)

#define CASE(x)   cout << "Case #" << x << ": ";

int n,m;

int poss(int r1 , int c1 , int r2 , int c2)
{
    if(!(r1 >= 0 && r1 < n && r2 >= 0 && r2 < n && c1 >=0 && c1 < m && c2 >= 0 && c2 < m)) return 0;
    int dx = r2 - r1;
    int dy = c2 - c1;
    if(dx < 0 || dy < 0) return 0;
    return 1;
}

int dp[2][510][510];

int main()
{
    inp_s;
    FOR(i,0,2) FOR(j,0,510) FOR(k,0,510) dp[i][j][k] = 0;
    cin >> n >> m;
    vector<string> arr(n);
    FOR(i,0,n) cin >> arr[i];
    if(arr[0][0] == arr[n-1][m-1])
    dp[0][0][n-1] = 1;
    for(int moves = 1; 2*moves <= (n + m - 2); moves++)
    {
        FOR(i,0,n) FOR(j,0,n) dp[1][i][j] = 0;
        for(int r1 = 0; r1 < n; r1++)
        {
            for(int r2 = 0; r2 < n; r2++)
            {
                int c1 = moves - 1 - r1;
                int c2 = (n + m - 2) - moves - r2 + 1;
                if(!poss(r1,c1,r2,c2)) continue;
                int ways = dp[0][r1][r2];

                if(poss(r1+1,c1,r2-1,c2) && arr[r1+1][c1] == arr[r2-1][c2]) dp[1][r1+1][r2-1] = (dp[1][r1+1][r2-1] + ways)%MOD;
                if(poss(r1,c1+1,r2-1,c2) && arr[r1][c1+1] == arr[r2-1][c2]) dp[1][r1][r2-1] = (dp[1][r1][r2-1] + ways) % MOD;

                if(poss(r1+1,c1,r2,c2-1) && arr[r1+1][c1] == arr[r2][c2-1]) dp[1][r1+1][r2] = (dp[1][r1+1][r2] + ways) % MOD;
                if(poss(r1,c1+1,r2,c2-1) && arr[r1][c1+1] == arr[r2][c2-1]) dp[1][r1][r2] = (dp[1][r1][r2] + ways) % MOD;

            }
        }
        FOR(i,0,n) FOR(j,0,n) dp[0][i][j] = dp[1][i][j];
    }
    int ans = 0;
    FOR(i,0,n) FOR(j,0,n) ans = (ans + dp[0][i][j]) % MOD;
    cout << ans << endl;
    return 0;
}