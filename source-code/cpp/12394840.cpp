//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

struct edge {
   int x, l, n;
   edge() {}
   edge(int x, int l, int n) : x(x), l(l), n(n) {}
};

struct vert {
   long long p;
   int x;
   vert() {}
   vert(long long p, int x) : p(p), x(x) {}

   bool operator <(const vert& a) const {
      if (p == a.p) {
         return x < a.x;
      } else {
         return p < a.p;
      }
   }
};

struct seg {
   long long l, r;
   int n;
   seg() {}
   seg(long long l, long long r, int n) : l(l), r(r), n(n) {}

   bool operator <(const seg& a) const {
      if (l == a.l) {
         return r < a.r;
      } else {
         return l < a.l;
      }
   }
};

void deikstra(const int& s, const int& k, const vector<vector<vector<edge> > >& g, vector<vector<long long> >& d) {
   set<vert> q;
   for (int i = 0; i < (int)g.size(); ++i) {
      if (i != s) {
         q.insert(vert(d[i][k], i));
      }
   }
   d[s][k] = 0;
   q.insert(vert(0, s));
   for (; (int)q.size() > 0;) {
      int v = q.begin()->x;
      q.erase(q.begin());
      for (auto to : g[v][k]) {
         if (d[to.x][k] > d[v][k] + to.l) {
            q.erase(vert(d[to.x][k], to.x));
            d[to.x][k] = d[v][k] + to.l;
            q.insert(vert(d[to.x][k], to.x));
         }
      }
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n, m, s, t;
   scanf("%d%d%d%d", &n, &m, &s, &t);
   --s; --t;
   vector<vector<long long> > d(n, vector<long long> (2, (long long)1e15 + 7));
   vector<vector<vector<edge> > > g(n, vector<vector<edge> > (2));
   for (int i = 0; i < m; ++i) {
      int a, b, l;
      scanf("%d%d%d", &a, &b, &l);
      --a; --b;
      g[a][0].push_back(edge(b, l, i));
      g[b][1].push_back(edge(a, l, i));
   }
   deikstra(s, 0, g, d);
   deikstra(t, 1, g, d);
   vector<seg> tp;
   vector<bool> ans(m, 0);
   for (int i = 0; i < n; ++i) {
      for (auto to : g[i][0]) {
         if (d[i][0] + d[to.x][1] + to.l == d[t][0]) {
            tp.push_back(seg(d[i][0], d[to.x][0], to.n));
         } else {
            ans[to.n] = 1;
         }
      }
   }
   sort(tp.begin(), tp.end());
   int x = 0;
   for (int i = 1; i < (int)tp.size(); ++i) {
      if (tp[x].r > tp[i].l) {
         ans[tp[x].n] = 1;
         ans[tp[i].n] = 1;
      }
      if (tp[x].r < tp[i].r) {
         x = i;
      }
   }
   vector<int> anq(m, 0);
   for (int i = 0; i < n; ++i) {
      for (auto to : g[i][0]) {
         if (!ans[to.n]) {
            continue;
         } 
         if (d[t][0] > d[i][0] + d[to.x][1] + 1) {
            anq[to.n] = int(to.l - d[t][0] + d[i][0] + d[to.x][1] + 1);
         } else {
            anq[to.n] = -1;
         }
      }
   }
   for (int i = 0; i < m; ++i) {
      if (anq[i] == -1) {
         puts("NO");
      }
      if (anq[i] == 0) {
         puts("YES");
      }
      if (anq[i] > 0) {
         printf("CAN %d\n", anq[i]);
      }
   }
   return 0;
}