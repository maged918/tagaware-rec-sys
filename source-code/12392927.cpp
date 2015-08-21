//Language: GNU C++11


#include <bits/stdc++.h>

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(V) (int) V.size()
#define LN(V) (int) V.length()
#define ALL(V) V.begin(), V.end()
using namespace std;

const int N = 2 * 1e5 + 10;

long long n, k, a[N], res;
map <long long, long long> tot;
map <long long, long long> cnt;

int main() {

    ios_base::sync_with_stdio(0);

//    freopen("in", "r", stdin); freopen("out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i], tot[a[i]]++;

//    sort(a, a + n);

    for (int i = 0; i < n; i++) {

        if (i == 0) {

            cnt[a[i]]++;
            continue;
        }

        if (a[i] % k == 0) {

            long long up = a[i] * k;

//            cout << up << "\n";

            if (up < 2000000000) {

                if (k == 1 || a[i] == 0) res += cnt[a[i]] * (max(tot[a[i]] - cnt[a[i]] - 1, 0LL));
                else {

                        res += cnt[a[i] / k] * (tot[up] - cnt[up]);
//                        cout << up << "\n";
//                        cout << tot[up] << " " << cnt[up] << "\n";
                }
            }
        }

        cnt[a[i]]++;
    }

    cout << res;

    return 0;
}
