//Language: GNU C++11


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int INF = (int) 1.01e9;
const ld EPS = 1e-9;

void precalc() {
}

int n, m;
const int maxn = (int) 5e5 + 10;

int pr[maxn];
char str[maxn];

int vs[maxn], hs[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  pr[0] = -1;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &pr[i]);
    --pr[i];
  }
  scanf("%s", str);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &vs[i], &hs[i]);
    --vs[i], --hs[i];
  }
  return 1;
}

vector<vector<int> > es;
int depth[maxn];

int H;

vector<int> layer[maxn], prec[maxn];

int start[maxn], finish[maxn];
int Time;

void dfs(int v) {
  start[v] = Time++;
  if (depth[v] > H) {
    H = depth[v];
    layer[H].clear();
    prec[H].clear();
    prec[H].pb(0);
  }
  //eprintf("add to h = %d, v = %d, c = %d\n", depth[v], v, str[v] - 'a');
  layer[depth[v]].pb(v);
  prec[depth[v]].pb(prec[depth[v]].back() ^ (1 << (str[v] - 'a')));
  for (int it = 0; it < sz(es[v]); ++it) {
    int u = es[v][it];
    depth[u] = depth[v] + 1;
    dfs(u);
  }
  finish[v] = Time++;
}

int findPos(vector<int> &a, int T) {
  int l = -1, r = sz(a);
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (start[a[m]] < T) {
      l = m;
    } else {
      r = m;
    }
  }
  return r;
}

void solve() {
  es = vector<vector<int> >(n);
  for (int i = 1; i < n; ++i) {
    es[pr[i]].pb(i);
  }
  depth[0] = 0;
  H = -1;
  Time = 0;
  dfs(0);

  for (int iter = 0; iter < m; ++iter) {
    int v = vs[iter], h = hs[iter];
    if (h > H) {
      printf("Yes\n");
      continue;
    }
    int left = findPos(layer[h], start[v]);
    int right = findPos(layer[h], finish[v]);
    int mask = (prec[h][right] ^ prec[h][left]);
    if (mask & (mask - 1)) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
