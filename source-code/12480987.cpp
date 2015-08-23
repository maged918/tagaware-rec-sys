//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi> vvi;
typedef vector <ii> vii;
typedef vector <vii> vvii;
#define PB push_back
#define MP make_pair
#define OO (1000000000)
#define EPS (1e-9)
#define MOD (1000000007)
#define all(v) ((v).begin()),((v).end())
#define DEBUG(x) cout<< #x <<" = "<<"\""<< (x) <<"\""<<endl
void read_file(bool outToFile = true){
#ifdef LOCAL_TEST
    freopen("in.in", "rt", stdin);
    if(outToFile)
    freopen("out.out", "wt", stdout);
#endif
}
//
#define nMax 4000+1
int n;
int dp[nMax][nMax];
int C[nMax][nMax];
int eq[nMax];
//
void build(){
    memset(C, 0, sizeof C);
    for(int i=0; i<nMax; i++)
        C[i][i] = C[i][0] = 1;
    
    for(int i=2; i<nMax; i++)
        for(int j=1; j<i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j], C[i][j] %= MOD;
    
    dp[0][0] = 1;
    for(int j=1; j<nMax; j++)
        dp[0][j] = 0;
    
    for(int i=1; i<nMax; i++)
        for(int j=0; j<nMax; j++)
            dp[i][j] = 1LL*dp[i-1][j]*j%MOD + (j-1>=0? dp[i-1][j-1] : 0), dp[i][j] %= MOD;
    
    for(int i=0; i<nMax; i++)
    {
        eq[i] = 0;
        for(int j=0; j<nMax; j++)
            eq[i] += dp[i][j], eq[i] %= MOD;
    }
}
//
int main()
{
    read_file(false);
    build();
    while(cin>>n)
    {
        int ans = 0;
        for(int m=0; m<n; m++)
            ans += 1LL * C[n][n-m] * eq[m] %MOD, ans %= MOD;
        cout<< ans <<endl;
    }
}
