//Language: GNU C++


/* Supto
   Dept. Of CSE
   University Of Dhaka
*/
#include<bits/stdc++.h>

#define pb push_back
#define ins insert
#define ff first
#define ss second
#define ll long long int
#define llu long long unsigned
#define sss stringstream
#define oss ostringstream
#define iss istringstream
#define pii pair<int,int>
#define _sq(x) ((x)*(x))
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define mem(a) memset(a,0,sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
#define ctz(x) __builtin_ctz(x) //number of trailing zeroes in a digit
#define ctzl(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(x)
#define clzl(x) __builtin_clzll(x) //number of leading zeroes in a digit
//If Long Long (mask & (1LL << k))
#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))
#define set0(mask ,k) (mask & (~(1<<k)))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;
#define pi acos(-1.0)
#define inf (1<<30)
#define eps 1e-9
#define MAX 500005
#define MAXL 15

//const ll mod = 1000000007;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};
vector <int> G[MAX];
vector < pii > store[MAX];
int in[MAX], out[MAX], idx[35], timer;
char ar[MAX];
void gen()
{
    for(int i = 0; i < 30; i++) idx[i] = (1<<i);
}
void dfs(int u, int dep)
{
    in[u] = ++timer;
    pii tmp;
    if(!store[dep].empty()) tmp = store[dep].back();
    else tmp = make_pair(0, 0);
    store[dep].pb(make_pair(timer, tmp.ss^idx[ar[u]-97]));
    int i, sz = G[u].size();
    for(i = 0; i < sz; i++)
    {
        dfs(G[u][i], dep+1);
    }
    out[u] = ++timer;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    //ios_base::sync_with_stdio(false);
    int n, m, i, v, h;
    scanf("%d %d", &n, &m);
    for(i = 1; i < n; i++)
    {
        scanf("%d", &v);
        G[v].pb(i+1);
    }
    scanf("%s", ar+1);
    gen();
    timer = 0;
    dfs(1, 1);
    while(m--)
    {
        scanf("%d %d", &v, &h);
        int l = lower_bound(store[h].begin(), store[h].end(), make_pair(in[v], -1))-store[h].begin()-1;
        int r = lower_bound(store[h].begin(), store[h].end(), make_pair(out[v], -1))-store[h].begin()-1;
        int res = 0;
        if(r >= 0) res ^= store[h][r].ss;
        if(l >= 0) res ^= store[h][l].ss;
        res -= (res&-res);
        if(res == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
