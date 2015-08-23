//Language: GNU C++11


#include <bits/stdc++.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <time.h>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
///cout << fixed << setprecision(13) << (double) x << endl;
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pi acos(-1.0)
#define eps 1e-8
#define Mp(a, b) make_pair(a, b)
#define asd puts("asdasdasdasdasdf");
typedef long long ll;
typedef pair <int, int> pl;
//typedef __int64 LL;
const int inf = 0x3f3f3f3f;
const int N = 500050;

vector <int> xr[N];
vector <int> Dep[N];
int dep[N];
int L[N], R[N];
int rp[N];
int head[N];
char a[N];

struct node{
    int v, nxt;
}e[N];

int n, m, cnt;
int dfn;

void init()
{
    cnt = dfn = 0;
    memset( head, -1, sizeof( head ) );
    for( int i = 1; i <= n; ++i ) {
        xr[i].clear();
        Dep[i].clear();
    }
    dep[1] = 1;
}

void add( int u, int v )
{
    e[cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs( int u )
{
    L[u] = ++dfn;
    rp[L[u]] = u;
    Dep[dep[u]].push_back( L[u] );
    for( int i = head[u]; ~i; i = e[i].nxt ) {
        int v = e[i].v;
        dep[v] = dep[u] + 1;
        dfs( v );
    }
    R[u] = dfn;
}

int main()
{
    while( ~scanf("%d%d", &n, &m) ) {
        init();
        for( int i = 2, u; i <= n; ++i ) {
            scanf("%d", &u);
            add( u, i );
        }
        scanf("%s", a);
        dfs( 1 );
        for( int i = 1; i <= n; ++i ) {
            int sz = Dep[i].size();
            for( int j = 0; j < sz; ++j ) {
                xr[i].push_back( 0 );
                int x = a[rp[Dep[i][j]] - 1] - 'a';
                xr[i][j] |= (1<<x);
            }
            for( int j = 1; j < sz; ++j )
                xr[i][j] ^= xr[i][j-1];
        }
        int x, h;
        while( m-- ) {
            scanf("%d%d", &x, &h);
            int l = L[x], r = R[x];
            if( h < dep[x] ) {
                puts("Yes");
                continue;
            }
            int sz = Dep[h].size(), odd = 0;
            if( sz == 0 || l > Dep[h][sz-1] || r < Dep[h][0] ) {
                puts("Yes");
                continue;
            }
            int X = lower_bound( Dep[h].begin(), Dep[h].end(), l ) - Dep[h].begin();
            int Y = lower_bound( Dep[h].begin(), Dep[h].end(), r ) - Dep[h].begin();
            if( Y == sz || Dep[h][Y] > r )
                --Y;
            int tmp = xr[h][Y];
            if( X > 0 )
                tmp ^= xr[h][X-1];
            for( int i = 0; i < 26; ++i ) {
                if( tmp & ( 1 << i ) )
                    ++odd;
            }
            if( odd <= 1 )
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
