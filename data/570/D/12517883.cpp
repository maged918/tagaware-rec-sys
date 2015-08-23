//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5;

struct R {
    int c;
    int cnt[26];
    int t;

    R() {}
    R(int c, int t) : c(c), t(t) {}
};

int n, m;
vector< vector<int> > g;
vector< vector<R> > depth;
int tin[N], tout[N];
int ch[N];

int T = 0;

void dfs(int v, int d) {
    tin[v] = T++;
    while ((int)depth.size() < d + 1) depth.push_back(vector<R>());
    depth[d].push_back(R(ch[v], tin[v]));
    for (int u : g[v]) {
        dfs(u, d + 1);
    }
    tout[v] = T++;
}

void calc() {
    for (int i = 0; i < depth.size(); i++) {
        for (int j = 0; j < depth[i].size(); j++) {
            R &cur = depth[i][j];
            memset(cur.cnt, 0, sizeof cur.cnt);
            cur.cnt[cur.c]++;
            if (j > 0) {
                for (int k = 0; k < 26; k++) {
                    cur.cnt[k] += depth[i][j - 1].cnt[k];
                }
            }
        }
    }
}

bool canpalind(int c[26]) {
    bool odd = false;
    for (int i = 0; i < 26; i++) {
        if (c[i] % 2 == 1) {
            if (!odd) odd = true;
            else return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    g.resize(n);

    for (int i = 1; i <= n - 1; i++) {
        int p;
        scanf("%d", &p);
        p--;
        g[p].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        char tmp;
        scanf(" %c", &tmp);
        ch[i] = tmp - 'a';
    }

    dfs(0, 1);

    calc();

    for (int i = 0; i < m; i++) {
        int v, h;
        scanf("%d%d", &v, &h);
        //asd asd
        v--;

        if (h + 1 > depth.size()) {
            puts("Yes");
            continue;
        }
        auto &curmas = depth[h];
        int c[26];
        memset(c, 0, sizeof c);
        {
            int l = 0, r = (int)curmas.size();
            while (l + 1 < r) {
                int md = (l + r) >> 1;
                if (curmas[md].t < tout[v]) {
                    l = md;
                } else {
                    r = md;
                }
            }
            if (curmas[l].t <= tout[v] && curmas[l].t >= tin[v]) {
                for (int k = 0; k < 26; k++) {
                    c[k] = curmas[l].cnt[k];
                }
            }
        }
        {
            int l = -1, r = (int)curmas.size() - 1;
            while (l + 1 < r) {
                int md = (l + r) >> 1;
                if (curmas[md].t < tin[v]) {
                    l = md;
                } else {
                    r = md;
                }
            }
            if (l >= 0) {
                for (int k = 0; k < 26; k++) {
                    c[k] -= curmas[l].cnt[k];
                }
            }
        }
        if (canpalind(c)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}