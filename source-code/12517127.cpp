//Language: GNU C++


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 5e5 + 1;
const int M = 1e9 + 7;

vector<int> g[N];
int h[N], tin[N], tout[N], cnt[N][26], cv[N], hc[N], timer = 0;
char str[N];
bool ans[N];

int sorted[N];

void dfs(int v, int height) {
    tin[v] = timer;
    h[v] = height;
    hc[height]++;
    sorted[timer] = v;
    ++timer;
    cv[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        dfs(to, height + 1);
        cv[v] += cv[to];
    }
}

const int s = 720;

struct Q {
    int l, r, h;
    int n;
    Q(int ll, int rr, int nn, int hh) : l(ll), r(rr), n(nn), h(hh) { }
    bool operator<(const Q & t) const {
        return r < t.r;
    }
};

vector<Q> buckets[s + 2];

int main() {
    int n, m;
    cin >> n >> m;
    bool l = 1;
    for (int i = 1; i < n; ++i) {
        int t;
        scanf("%d", &t);
        l &= t == i;
        g[t - 1].push_back(i);
    }
    scanf("%s", &str);
    for(int i = 0; i < n; ++i) str[i] -= 'a';
    dfs(0, 1);
    for (int i = 0; i < m; ++i) {
        int v, height;
        scanf("%d%d", &v, &height);
        --v;
        int vin = tin[v];
        if (hc[height] == 1) ans[i] = 1;
        else buckets[vin / s].push_back(Q(vin, vin + cv[v], i, height));
    }
    for (int i = 0; i < s + 2; ++i) {
        if (buckets[i].size() == 0) continue;
        sort(buckets[i].begin(), buckets[i].end());  
        int l = buckets[i][0].l;
        int r = l-1;
        for (int j = 0; j < buckets[i].size(); ++j) {
            int rl = buckets[i][j].l;
            int rr = buckets[i][j].r-1;
            while (r < rr) {
                ++r;
                int v = sorted[r];
                cnt[h[v]][str[v]]++;              
            }
            while (l < rl) {
                int v = sorted[l];
                cnt[h[v]][str[v]]--;
                ++l;
            }
            while (l > rl) {
                --l;
                int v = sorted[l];
                cnt[h[v]][str[v]]++;              
            }
            int total = 0, odd = 0;
            int rh = buckets[i][j].h;
            for (int k = 0; k < 26; ++k) {
                total += cnt[rh][k];
                odd += cnt[rh][k] & 1;
            }
            ans[buckets[i][j].n] = odd <= (total & 1);
        }
        while (l <= r) {
            int v = sorted[l];
            cnt[h[v]][str[v]]--;
            ++l;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i]) printf("Yes\n");
        else printf("No\n");
    }
}