//Language: GNU C++11


#include <bits/stdc++.h>
#define eps 1e-9
#define FOR(x, s, e) for(int x = (s); x < (e); ++x)
#define FORc(x, s, e, c) for(int x = (s); x < (e) && (c); ++x)
#define ROF(x, s, e) for(int x = (s); x >= (e); --x)
#define ROFc(x, s, e, c) for(int x = (s); x >= (e) && (c); --x)
#define EXP(i, s) for (int i = (s); i; i = qn[i])
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pb push_back
#define mp make_pair
#define vs vector<string>
#define ALL(X) X.begin(), X.end()
#define LL long long
#define pii pair<int, int>
#define x first
#define y second
#define gcd(x, y) __gcd((x), (y))
#define countbit(x) __builtin_popcount(x)
#define has count
#define endl '\n'

using namespace std;
struct _{ios_base::Init i;_(){cin.sync_with_stdio(0);cin.tie(0);}}_;

int N, Q;

#define MAXN 800000
int par[MAXN];
vi adj[MAXN];
string s;
int birth_time[MAXN], death_time[MAXN];
int heights[MAXN];
vii by_height_mask[MAXN];

void preprocess(int u, int p, int& traversal_time, int height = 1) {
  heights[u] = height;
  birth_time[u] = ++traversal_time;
  int past_mask = by_height_mask[height].empty() ? 0 : by_height_mask[height].back().y;
  by_height_mask[height].pb(mp(traversal_time, past_mask ^ (1 << (s[u] - 'a'))));
  for (auto& v : adj[u]) {
    if (v != p) {
      preprocess(v, u, traversal_time, height + 1);
    }
  }
  death_time[u] = ++traversal_time;
}

int main(int argc, char **argv){
  cin >> N >> Q;
  FOR(i, 1, N) {
    cin >> par[i];
    par[i]--;
    adj[par[i]].pb(i);
  }
  cin >> s;
  int traversal_time = 0;
  preprocess(0, -1, traversal_time);
  FOR(q, 0, Q) {
    int v, h;
    cin >> v >> h;
    --v;
    if (heights[v] >= h) {
      puts("Yes");
    } else {
      int start = lower_bound(ALL(by_height_mask[h]), mp(birth_time[v], -1)) - by_height_mask[h].begin();
      int end = (int)(upper_bound(ALL(by_height_mask[h]), mp(death_time[v], 27)) - by_height_mask[h].begin()) - 1;
      if (end < start || start >= by_height_mask[h].size()) {
        puts("Yes");
      } else {
        int segment_mask = (start ? by_height_mask[h][start - 1].y : 0) ^ by_height_mask[h][end].y;
        if (segment_mask == 0 || ((segment_mask & (-segment_mask)) == segment_mask)) {
          puts("Yes");
        } else {
          puts("No");
        }
      }
    }
  }
  return 0;
}
