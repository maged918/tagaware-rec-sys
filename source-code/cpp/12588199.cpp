//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

bool marked[MAXN];
int x[MAXN];
int n, k, a, m;

int getShips(int shots) {
   memset(marked, false, sizeof marked);
   marked[n+1] = true;

   int res = 0;
   for (int i = 0; i < shots; i++) marked[x[i]] = true;
   for (int i = 1, len = 0; i <= n + 1; i++) {
      if (marked[i]) {
         int ships = (len + 1) / (a + 1);
         res += ships;
         len = 0;
      }
      else len++;
   }
   return res;
}

int main() {
//   freopen("input.txt", "r", stdin);

   ios::sync_with_stdio(false);
   cin >> n >> k >> a;
   cin >> m;
   for (int i = 0; i < m; i++) cin >> x[i];

   int l = 1, r = m, mid;
   while (l + 1 < r) {
      mid = (l + r) >> 1;
      if (getShips(mid) >= k) l = mid;
      else r = mid;
   }
   if (getShips(l) < k) cout << l << endl;
   else if (getShips(r) < k) cout << r << endl;
   else cout << -1 << endl;

   return 0;
}
