//Language: GNU C++


#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define pli pair<ll, int>
using namespace std;

const int MAXN = 100005;
const ll HUGE = 10000000000000000LL;

struct r {
       int x, w, ind;
       r(int a = 0, int b = 0, int c = 0) {
             x = a; w = b; ind = c;
       }
};

int n, m, st, t;
pli arr[MAXN];
ll dists[MAXN], distt[MAXN];
set<pli> s;
bool nec[MAXN];
vector<r> in[MAXN], out[MAXN];
int sol[MAXN], open[MAXN];

int main (void) {
    ios::sync_with_stdio(false);
    cin >> n >> m >> st >> t;
    for (int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        out[x].push_back(r(y, w, i));
        in[y].push_back(r(x, w, i));
    }
    for (int i=1; i<=n; i++) {
        dists[i] = HUGE;
        distt[i] = HUGE;
    }
    dists[st] = 0;
    s.insert(make_pair(0, st));
    while (!s.empty()) {
          pli curr = *(s.begin());
          ll f = curr.first;
          int sec = curr.second;
          s.erase(curr);
          for (int i=0; i<out[sec].size(); i++)
              if (dists[out[sec][i].x] > f + out[sec][i].w) {
                 s.erase(make_pair(dists[out[sec][i].x], out[sec][i].x));
                 dists[out[sec][i].x] = f + out[sec][i].w;
                 s.insert(make_pair(dists[out[sec][i].x], out[sec][i].x));
              }
    }
    distt[t] = 0;
    s.insert(make_pair(0, t));
    while (!s.empty()) {
          pli curr = *(s.begin());
          ll f = curr.first;
          int sec = curr.second;
          s.erase(curr);
          for (int i=0; i<in[sec].size(); i++)
              if (distt[in[sec][i].x] > f + in[sec][i].w) {
                 s.erase(make_pair(distt[in[sec][i].x], in[sec][i].x));
                 distt[in[sec][i].x] = f + in[sec][i].w;
                 s.insert(make_pair(distt[in[sec][i].x], in[sec][i].x));
              }
    }
    for (int i=0; i<n; i++) 
        arr[i] = make_pair(dists[i + 1], i + 1);
    sort(arr, arr + n); 
    int opcnt = 1;
    open[st] = 1;
    for (int i=0; i<n; i++) {
        int c = arr[i].second;
        ll d = arr[i].first;
        if (opcnt == 1 && open[c] == 1) 
           nec[c] = 1;
        if (open[c] == 1) {
           opcnt--; 
           open[c] = 0;
        }
        int cnt = 0;
        for (int j=0; j<out[c].size(); j++)
            if (d + out[c][j].w + distt[out[c][j].x] == dists[t]) {
               if (!open[out[c][j].x]) {
                  open[out[c][j].x] = 1;
                  opcnt++;
               }              
               cnt++;
        }
        for (int j=0; j<out[c].size(); j++) {
            if (d + out[c][j].w + distt[out[c][j].x] != dists[t]) {
               ll v = d + out[c][j].w + distt[out[c][j].x] - dists[t] + 1;
               if (out[c][j].w > v) 
                  sol[out[c][j].ind] = v;
               else
                   sol[out[c][j].ind] = -1;
               continue;
            }
            if (cnt == 1 && nec[c]) 
               continue;
            if (out[c][j].w > 1)
               sol[out[c][j].ind] = 1;
            else
                sol[out[c][j].ind] = -1;
        }
    }   
    for (int i=0; i<m; i++) {
        if (sol[i] == -1)
           cout << "NO" << endl;
        else 
             if (sol[i] == 0)
                cout << "YES" << endl;
        else 
             cout << "CAN " << sol[i] << endl;
    }
    return 0;
}
