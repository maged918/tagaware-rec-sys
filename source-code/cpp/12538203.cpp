//Language: MS C++



#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <set>
#include <ctime>
#include <cmath>
#include <assert.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a; i<(int)n; i++)
#define per(i,n,a) for (int i=n; i>=a; i--)
#define mp make_pair
#define PI 3.141592653589793
#define clr(a) memset(a, 0, sizeof(a))
#define clr1(a) memset(a, -1, sizeof(a))
typedef vector<int> VI;
typedef vector< pair<int, int> > VIP;
typedef vector<string> VS;
typedef vector <double> VD;
typedef vector <bool> VB;
typedef long long ll;
#define MAX_V 1000
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
    ll res = 1; a %= mod; for (; b; b >>= 1){ if (b & 1)res = res*a%mod; a = a*a%mod; }return res;
}

#define MAX_N 500001

int n, m, a, b, now;
int parent[MAX_N], dep[MAX_N];
VI child[MAX_N];
char s[MAX_N + 1];
int inCnt[MAX_N], outCnt[MAX_N];
VI cnt[MAX_N][26];

void dfs(int idx) {
    dep[idx] = dep[parent[idx]] + 1;
    int d = dep[idx];
    cnt[d][s[idx - 1] - 'a'].push_back(++now);
    inCnt[idx] = now;
    rep(i, 0, child[idx].size()) {
        dfs(child[idx][i]);
    }
    outCnt[idx] = now;
}

int main()
{
    scanf("%d%d", &n, &m);
//  cin >> n >> m;
    rep(i, 2, n + 1) {
        scanf("%d", &a);
//      cin >> a;
        parent[i] = a;
        child[a].push_back(i);
    }
    scanf("%s", s);
//  cin >> s;
    dfs(1);
    
    rep(i, 0, m) {
        scanf("%d%d", &a, &b);
//      cin >> a >> b;

        if (dep[a] >= b) {
            printf("Yes\n");
//          cout << "Yes" << endl;
            continue;
        }

        int cc = 0;
        rep(j, 0, 26) {
            int c = upper_bound(cnt[b][j].begin(), cnt[b][j].end(), outCnt[a]) - lower_bound(cnt[b][j].begin(), cnt[b][j].end(), inCnt[a]);
            if (c % 2) cc++;
            if (cc > 1) break;
        }

        if (cc > 1) printf("No\n");  // cout << "No" << endl;
        else printf("Yes\n");  // cout << "Yes" << endl;
    }

    return 0;
}