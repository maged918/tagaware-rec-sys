//Language: GNU C++11


//#include "testlib.h"
//#include <spoj.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <set>
#include <numeric>
#include <map>
#include <queue>

using namespace std;

const int mod1 = 1e9+9;
const int mod2 = 1e9+7;

vector< pair<int, int> > g[3][111111];
int a[111111], b[111111], c[111111];

long long dist[3][111111];
long long cnt1[3][111111];
long long cnt2[3][111111];
int looked[111111];

int n;

void bfs(int t, int start) {
    
    
    for(int i = 0; i <= n; ++i) {
        cnt1[t][i] = 0;
        cnt2[t][i] = 0;
        looked[i] = 0;
    }
    cnt1[t][start] = 1;
    cnt2[t][start] = 1;
    
    set<pair<long long, int> > s;
    s.insert({0, start});
    while (!s.empty()) {
        int v = s.begin()->second;
        long long d = s.begin()->first;
        s.erase(s.begin());
        
        if (looked[v]) continue;
        looked[v] = 1;
        
        for(auto to : g[t][v]) {
            if (dist[t][to.first] != dist[t][v] + to.second) continue;
            
            cnt1[t][to.first] += cnt1[t][v];
            cnt2[t][to.first] += cnt2[t][v];
            if (cnt1[t][to.first] >= mod1)
                cnt1[t][to.first] -= mod1;
            if (cnt2[t][to.first] >= mod2)
                cnt2[t][to.first] -= mod2;
            s.insert({dist[t][to.first], to.first});
        }
    }
}

void megaDj(int t, int start) {
    for(int i = 0; i <= n; ++i)
        dist[t][i] = 1e17;
    
    set<pair<long long, int> > s;
    dist[t][start] = 0;
    s.insert({dist[t][start], start});
    
    while (!s.empty()) {
        int v = s.begin()->second;
        long long d = s.begin()->first;
        s.erase(s.begin());
        
        if (dist[t][v] != d) continue;
        
        for(auto to : g[t][v]) {
            if (dist[t][to.first] > d + to.second) {
                dist[t][to.first] = d + to.second;
                s.insert({dist[t][to.first], to.first});
            }
        }
    }
    bfs(t, start);
}

int main() {
    ios::sync_with_stdio(0);
    int m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        g[1][a[i]].push_back({b[i], c[i]});
        g[2][b[i]].push_back({a[i], c[i]});
    }
    
    megaDj(1, s);
    megaDj(2, t);
    
    
    long long DIST = dist[1][t];
    
    for(int i = 0; i < m; ++i) {
        int A = a[i], B = b[i];
        long long C = c[i];
        
        
        
        if (dist[1][A] + dist[2][B] + 1 > DIST) {
            cout << "NO\n";
            continue;
        }
        
        if ( dist[1][A] + dist[2][B] + C == DIST &&
            ((cnt1[1][A] * cnt1[2][B]) % mod1 == cnt1[1][t] &&
             (cnt2[1][A] * cnt2[2][B]) % mod2 == cnt2[1][t])) {
                cout << "YES\n";
                continue;
            }
        
        
        
        if (dist[1][A] + dist[2][B] + 1 < DIST) {
            cout << "CAN " << C - (DIST - dist[1][A] - dist[2][B]) + 1 << "\n";
            continue;
        }
        
        
        
        cout << "NO\n";
    }
    return 0;
}