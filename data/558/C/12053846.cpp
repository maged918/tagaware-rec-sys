//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define md int(1e7+100)
#define modul int(1e9+7)
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORE(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)

using namespace std;

typedef pair<int, int> II;
typedef vector<II> vi;
typedef long long ll;

int n, a[110010], k, f[1100010], cnt, cnt2, res, p, g[1100010];

int main()
{
    ios::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) {
        k = a[i];
        cnt = 0;
        g[k] += 1;
        while (k*2 <= 1100000) {
            k = k * 2;
            cnt++;
            f[k] += cnt;
            g[k] += 1;
        }
        cnt = 0;
        k = a[i];
        while (1) {
            while (k % 2 == 0) {
                cnt++;
                k /= 2;
                f[k] += cnt;
                g[k] += 1;
            }
            cnt++;
            k/=2;
            if (k == 0) break;
            f[k] += cnt;
            g[k] += 1;
            cnt2 = cnt;
            p = k;
            while (p*2 <= 1100000) {
                p = p * 2;
                cnt2++;
                f[p] += cnt2;
                g[p] += 1;
            }
        }
    }
    res = 1000000000;
    FOR(i,1,1100000)
        if (f[i] < res && g[i] == n) res = f[i];
    cout << res;
    return 0;
}
