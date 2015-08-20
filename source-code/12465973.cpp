//Language: GNU C++11


#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>

#define pe pair<int, long long>
#define mp make_pair
#define fi first
#define se second

using namespace std;

class cmp {
public:
    inline bool operator()(const pe &a, const pe &b) {
        return a.se > b.se;
    }
};

struct mu {
    int a, b;
    long long c;
    mu(int _a = 0, int _b = 0, long long _c = 0) {
        a = _a;
        b = _b;
        c = _c;
    }
};


const int MAX_N = 100100;
const long long INF = (1LL << 60);

vector<mu> edges;

vector<pe> A[MAX_N];
vector<pe> B[MAX_N];
vector<int> C[MAX_N];

int n;
long long d1[MAX_N], d2[MAX_N];
long long ans[MAX_N];
bool viz[MAX_N];

void dijkstra(int s, vector<pe> A[MAX_N], long long d[MAX_N]) {
    for(int i = 1; i <= n; i++) {
        d[i] = INF;
        viz[i] = false;
    }

    priority_queue<pe, vector<pe>, cmp> Q;

    Q.push(mp(s, 0));
    d[s] = 0;
    while(!Q.empty()) {
        int nod = Q.top().fi;
        Q.pop();
        if(viz[nod]) {
            continue;
        }

        viz[nod] = true;

        for(auto it : A[nod]) {
            if(d[nod] + it.se < d[it.fi]) {
                d[it.fi] = d[nod] + it.se;
                Q.push(mp(it.fi, d[it.fi]));
            }
        }
    }
}


int l[MAX_N];
int h[MAX_N];

void dfs(int nod, int niv, int dad) {
    h[nod] = l[nod] = niv;

    for(auto it : C[nod]) {
        int vec = edges[it].a + edges[it].b - nod;
        if(!l[vec]) {
            dfs(vec, niv + 1, it);
            h[nod] = min(h[nod], h[vec]);
        }
        else if (it != dad){
            h[nod] = min(h[nod], l[vec]);
        }

        if(h[vec] > l[nod]) {
            ans[it] = -2;
        }
    }
}

int main() {
    //ifstream cin("fis.in");
    //ofstream cout("fis.out");

    int m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        A[a].push_back(mp(b, c));
        B[b].push_back(mp(a, c));
        edges.push_back(mu(a, b, c));
    }

    dijkstra(s, A, d1);
    dijkstra(t, B, d2);

    long long cost = d1[t];

    for(int i = 0; i < (int)edges.size(); i++) {
        if(d1[edges[i].a] + d2[edges[i].b] + edges[i].c == cost) {
            C[edges[i].a].push_back(i);
            C[edges[i].b].push_back(i);
        }
        else {
            long long val = d1[edges[i].a] + d2[edges[i].b] + edges[i].c - cost + 1;
            if(val >= edges[i].c) {
                ans[i] = -1;
            }
            else {
                ans[i] = val;
            }
        }
    }

    dfs(s, 1, -1);

    for(int i = 0; i < m; i++) {
        if(!ans[i]) {
            if(edges[i].c > 1) {
                cout << "CAN 1\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else if(ans[i] == -1) {
            cout << "NO\n";
        }
        else if(ans[i] == -2) {
            cout << "YES\n";
        }
        else {
            cout << "CAN " << ans[i] << '\n';
        }
    }

    return 0;
}
