//Language: GNU C++


//
//  Created by x4150
//  Copyright (c) 2015 x4150. All rights reserved.
//
//#define DEBUG
 
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <complex>
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
 
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
#define LF '\n'
#define mod 1000000007
#define PII pair<int, int> 
#define PDD pair<long double, long double> 
#define mclear(p, x) memset(p, x, sizeof(p))
 
typedef vector<vector<int> > matrixInt;
typedef vector<vector<bool> > matrixBool;
template<class T> inline void umax(T &a, T b) { if(a<b) a = b; }
template<class T> inline void umin(T &a, T b) { if(a>b) a = b; }
template<class T> inline T max(T a, T b, T c) { return max(a, max(b, c)); }
template<class T> inline T min(T a, T b, T c) { return min(a, min(b, c)); }

ll power(ll n, ll e)
{
    ll ans = 1;
    while(e)
    {
        if (e&1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        e >>= 1;
    }
    return ans;
}
const int MAXN = 200005;
static ll fact[MAXN], inv_fact[MAXN];
void PreCompute()
{
    fact[0] = inv_fact[0] = 1;
    fact[1] = inv_fact[1] = 1;

    for (int i = 2; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = (inv_fact[i - 1] * power(i, mod - 2)) % mod;
    }
}

ll Solve(int x, int y)
{
    //(x + y - 2) C (y - 1)
    return (((fact[x + y - 2] * inv_fact[y - 1]) % mod) * inv_fact[x - 1]) % mod;
    /*ll num = 1, den = 1;
    for (int i = y; i < x + y - 1; i++)
        num = (num * i) % mod;
    for (int i = 2; i < x; i++)
        den = (den * i) % mod;
    return (num * power(den, mod - 2)) % mod;*/
}

bool Compare(const PII &a, const PII &b)
{
    if (a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff < b.ff;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifdef DEBUG
        freopen("in", "r", stdin);
        if (argc > 1)
        	freopen("out", "w", stdout);
    #endif

    int h, w, n, x, y;
    cin >> h >> w >> n;

    PreCompute();

    ll ans = Solve(h, w);
    vector<PII> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i] = PII(x, y);
    }
    sort(v.begin(), v.end(), Compare);

    ll arr[n];
    mclear(arr, 0);

    ll ans2 = 0;
    for(int i = 0; i < n; i++)
    {
        x = v[i].ff;
        y = v[i].ss;
        ll temp = Solve(x, y) - arr[i];        
        for (int j = i + 1; j < n; j++)
        {
            int p, q;
            p = v[j].ff;
            q = v[j].ss;
            if (p < x || q < y)
                continue;
            arr[j] = (arr[j] + ((Solve(p - x + 1, q - y + 1) * temp) % mod)) % mod;
        }
        temp = (temp * Solve(h - x + 1, w - y + 1)) % mod;
        ans2 = (ans2 + temp) % mod;
    }

    ans = (ans - ans2) % mod;
    if (ans < 0)
        ans += mod;
    cout << ans << LF;
    
    #ifdef DEBUG
    	if (argc > 1)
    		fflush(stdout), fclose(stdout);
    #endif
    return 0;
}  