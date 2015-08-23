//Language: GNU C++11


#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define llong long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define pr pair<int, int>

using namespace std;

const int MXN = 2e5 + 1;
const double EPS = 1e-9;
int n, k, a, m;
llong hm;
bool deleted[MXN];
set<pr> s;
set<pr> :: iterator it;

int main() {
    scanf("%d%d%d%d", &n, &k, &a, &m);
    s.insert({1, n});
    hm = (n + 1) / (a + 1);
    for(int i = 1, x; i <= m; i++) {
        scanf("%d", &x);
        if(deleted[x]) continue;
        deleted[x] = 1;
        it = s.lower_bound({x, MXN}), it--;
        hm -= ((it -> S) - (it -> F) + 2) / (a + 1);
        hm += (x - (it -> F) + 1) / (a + 1);
        hm += ((it -> S) - x + 1) / (a + 1);
        s.insert({it -> F, x - 1});
        s.insert({x + 1, it -> S});
        s.erase(it);
        if(hm < k) {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
