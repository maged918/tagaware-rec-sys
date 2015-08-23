//Language: GNU C++11


#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <stdlib.h>  
#include <string.h>  
#include <limits.h>  
#include <vector>  
#include <string>  
#include <time.h>  
#include <math.h>  
#include <iomanip>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
using namespace std;
const int N = 5e5 + 100;
typedef long long ll;
typedef pair<int, int> pii;
struct BIT {
    int c[N], maxn;
    void init(int n) { maxn = n; memset(c, 0, sizeof c); }
    inline int Lowbit(int x) { return x&(-x); }
    void change(int i, int x)//i点增量为x
    {
        while (i <= maxn)
        {
            c[i] += x;
            i += Lowbit(i);
        }
    }
    int sum(int x) {//区间求和 [1,x]
        int ans = 0;
        for (int i = x; i >= 1; i -= Lowbit(i))
            ans += c[i];
        return ans;
    }
    int query(int l, int r) {
        return sum(r) + sum(l - 1); 
    }
}t[26];
int n, m;
char s[N];
vector<int>G[N], D[N];
int l[N], r[N], top;
vector<pii>query[N];
bool ans[N];
void dfs(int u, int fa, int dep) {
    D[dep].push_back(u);
    l[u] = ++top;
    for (auto v : G[u])
        if (v != fa)dfs(v, u, dep + 1);
    r[u] = top;
}
int main() {
    rd(n); rd(m);
    fill(ans, ans + m + 10, 1);
    for (int i = 0; i < 26; i++) t[i].init(n);
    for (int i = 2, u; i <= n; i++)rd(u), G[u].push_back(i);
    top = 0;
    dfs(1, 1, 1);
    scanf("%s", s + 1);
    for (int i = 1, u, v; i <= m; i++) {
        rd(u); rd(v); query[v].push_back(pii(u, i));
    }
    for (int i = 1; i <= n; i++)
    {
        if (D[i].size() == 0)break;
        for (auto v : D[i]) t[s[v] - 'a'].change(l[v], 1);
        
        for (pii Q : query[i])
        {
            int ou = 0;
            for (int j = 0; j < 26; j++)
            {
                if (t[j].query(l[Q.first], r[Q.first]))
                    ou += t[j].query(l[Q.first], r[Q.first]) & 1;
            }
            ans[Q.second] = ou <= 1;
        }
        for (auto v : D[i]) t[s[v] - 'a'].change(l[v], -1);
    }
    for (int i = 1; i <= m; i++)ans[i] ? puts("Yes") : puts("No");

    return 0;
}