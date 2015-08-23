//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)n; i++)
#define FORN(i, n) for (int i = 0; i <= (int)n; i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()

typedef long long ll;

int adjX[4] = { 0, -1, 1, 0 };
int adjY[4] = { -1, 0, 0, 1 };

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> a;
    for (int i = 0; i < m; ++i) {
        vector<int> vec(n);
        for (int j = 0; j < n; ++j) {
            cin >> vec[j];
        }
        a[max_element(ALL(vec)) - vec.begin() + 1]++;
    }
    int ans = -1;
    int maxx = -1;

    for (map<int, int>::iterator it = a.begin(); it != a.end(); it++) {
        if (it->second > maxx) {
            maxx = it->second;
            ans = it->first;
        }

    }
    cout << ans;
    return 0;
}