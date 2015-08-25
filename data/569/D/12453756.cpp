//Language: GNU C++


#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id<<1,l,mid
#define rs id<<1|1,mid+1,r
#define OFF(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(x) memset(x,0x3f,sizeof x)
typedef long long ll ;
typedef pair<int,int> pii ;
const int maxn = 1e5+50 ;
const int inf = 0x3f3f3f3f ;
const int MOD = 1e9+7 ;
const int N = 200;
int dp[5000][5000];
int main () {
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
//      freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    cin >> n;
    dp[1][1] = 1;
    dp[2][1] = 1; dp[2][2] = 2;
    for (int i = 3; i <= n + 1; i++) {
        dp[i][1] = dp[i-1][i-1];
        for (int j = 2; j <= i; j++) dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % MOD ;
//        cout << dp[i][j] << " " ;}
//        puts("");
    }
    cout << dp[n+1][n];
    return 0;
}
