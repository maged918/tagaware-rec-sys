//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define TRACE
#ifdef TRACE
#define trace1(x)			cerr<<#x<<": "<<x<<endl;
#define trace2(x, y)		cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x, y, z)		cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)	cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)

#endif

#define mp make_pair
#define pb push_back
#define fr first
#define se second
#define MOD(a, b)  (a < 0 ? (((a % b) + b) % b) : (a % b))


#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int N, M;
vector<int> adj[500001];
char S[500002];
vector<int> occ[500001][26];
int in[500001], out[500001], now;

int mxd = 0;

void dfs(int u, int depth)
{
    occ[depth][S[u]-'a'].push_back(++now);
    in[u]=now;
    for(auto& v: adj[u])
        dfs(v, depth+1);
    out[u]=now;
}

int main()
{
    scan(N);
    scan(M);
    for(int i=2; i<=N; i++)
    {
        int a;
        scan(a);
        adj[a].push_back(i);
    }
    scanf("%s", S+1);
    dfs(1, 1);
    while(M--)
    {
        int v, h;
        scan(v);
        scan(h);
        int odd=0;
        for(int i=0; i<26; i++)
        {
            int cnt= upper_bound(occ[h][i].begin(), occ[h][i].end(), out[v]) -
                     lower_bound(occ[h][i].begin(), occ[h][i].end(), in[v]);
            if(cnt%2==1)
            {
                odd++;
                if(odd>1)
                    break;
            }
        }
        if(odd>1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
