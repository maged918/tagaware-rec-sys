//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) int(a.size())

typedef unsigned long long ll;

const int MAXN = 75, MAXK = 105;

struct require {
   string s; int y;
   require(string _s, int _y) : s(_s), y(_y) {}
};

ll f[2][MAXN][MAXN];
vector <require> req[MAXN];
int n, k;

bool ok(int x, int y, int l, int r) {
   for (int i = 0; i < sz(req[x]); i++) {
      string s = req[x][i].s;
      int v = req[x][i].y;
      if (s == "=" && v != y && v != x) return false;
      else if (s == "<") {
         if ((l != -1 && (v < l || v > r)) || v == y) return false;
      }
      else if (s == ">") {
         if ((l != -1 && v >= l && v <= r) || v == y) return false;
      }
      else if (s == "<=") {
         if (v != y && v != x && l != -1 && (v < l || v > r)) return false;
      }
      else if (s == ">=") {
         if (v != y && v != x && l != -1 && v >= l && v <= r) return false;
      }
   }
   for (int i = 0; i < sz(req[y]); i++) {
      string s = req[y][i].s;
      int v = req[y][i].y;
      if (s == "=" && v != x && v != y) return false;
      else if (s == "<") {
         if ((l != -1 && (v < l || v > r)) || v == x) return false;
      }
      else if (s == ">") {
         if ((l != -1 && v >= l && v <= r) || v == x) return false;
      }
      else if (s == "<=") {
         if (v != x && v != y && l != -1 && (v < l || v > r)) return false;
      }
      else if (s == ">=") {
         if (v != x && v != y && l != -1 && v >= l && v <= r) return false;
      }
   }
   return true;
}

int main() {
//   freopen("input.txt", "r", stdin);

   ios::sync_with_stdio(false);
   cin >> n >> k;
   for (int i = 0; i < k; i++) {
      int x, y; string s; cin >> x >> s >> y;
      req[x].pb(require(s, y));
      if (s == "<") s = ">";
      else if (s == ">") s = "<";
      else if (s == "<=") s = ">=";
      else if (s == ">=") s = "<=";
      req[y].pb(require(s, x));
   }

   for (int i = 1; i < 2*n; i++) {
      if (ok(i, i+1, -1, -1))
         f[n&1][i][i+1] = 1;
   }

   for (int i = n-1; i >= 1; i--) {
      int next = i & 1;
      int cur = 1 - next;
      for (int l = 1; l <= 2*n; l++)
      for (int r = l; r <= 2*n; r++)
         f[next][l][r] = 0;
      for (int l = 1; l <= 2*n; l++)
      for (int r = l; r <= 2*n; r++) {
         if (f[cur][l][r] == 0) continue;
         if (l > 2 && ok(l-2, l-1, l, r))
            f[next][l-2][r] += f[cur][l][r];
         if (r < 2*n-1 && ok(r+1, r+2, l, r))
            f[next][l][r+2] += f[cur][l][r];
         if (l > 1 && r < 2*n && ok(l-1, r+1, l, r))
            f[next][l-1][r+1] += f[cur][l][r];
      }
   }

   cout << f[1][1][2*n] << endl;

   return 0;
}
