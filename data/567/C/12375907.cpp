//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;
#define f(k,n) for (int k=0;k<n;k++)
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define inf 1e9
#define i64 __int64
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define sqr(a) ((a)*(a))
#define eps 1e-4

unordered_map <int, i64> nums[3];

int main() {

    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n, k, t;
    cin >> n >> k;
    i64 res = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (abs(t) % k == 0) {
            res += nums[1][t/k];
            nums[1][t] += nums[0][t / k];
        }
        nums[0][t]++;
    }
    cout << res << endl;
    return 0;



}
