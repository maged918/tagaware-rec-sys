//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAXH 51

using namespace std;

long long h,q;
vector<pair<long long, long long> > v;
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> h >> q;
    long long ll = 1ll << (h-1);
    long long rr = (1ll << h) - 1;

    for (int i = 0; i < q; i++) {
        long long hh,l,r,a;
        cin >> hh >> l >> r >> a;
        while (hh < h) {
            l = 2 * l;
            r = 2 * r + 1;
            hh++;
        }

        if (a == 0) {
            v.push_back(make_pair(l,r));
        }
        else {
            ll = max(ll, l);
            rr = min(rr, r);
        }
    }
    v.push_back(make_pair(rr+1, (1ll << h) - 1));

    sort(v.begin(),v.end());

    for (auto p : v) {
        long long l = p.first, r = p.second;
        if (l > ll) {
            if (l - ll > 1 || ans != 0) {
                cout << "Data not sufficient!\n";
                return 0;
            }
            ans = ll;
        }
        ll = max(ll, r + 1);
    }

    if (ans == 0)
        cout << "Game cheated!\n";
    else
        cout << ans << '\n';
}
