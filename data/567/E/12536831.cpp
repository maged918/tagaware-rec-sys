//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <stack>
#include <cstring>
#include <functional>
#include <iomanip>
using namespace std;

//Defines
#define FIRST(a) (a).begin()
#define REMOVE_FIRST(a) (a).erase((a).begin())
#define REMOVE_LAST(a) (a).erase(--(a).end())
#define LAST(a) (--(a).end())
#define PRINT_ALL(a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ ) printf("%d ", *it);
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define FORD(i,n) for(int (i)=n; (i)>=0; --(i))
#define DBG(var) cerr << #var << " = " << var << endl;
#define pint pair<int, int>
#define vint vector<int>
#define PB push_back
#define LL long long int
#define ULL unsigned long long int
#define UI unsigned int
#define MP make_pair
#define f first
#define s second
#define TEST(name) freopen( (name), "r", stdin);
#define print(n) cout<<(n)<<endl
#define EXIT(message) {cout<<(message); exit(0);}
#define IOS ios_base::sync_with_stdio(0)
inline void scan(int &n){register char c = 0;while (c < 33) c=getc(stdin);n = 0;while (c>32) {n=n*10 + (c-'0'); c=getc(stdin);}}
inline void scan(LL &n){register char c = 0;while (c < 33) c=getc(stdin);n = 0;while (c>32) {n=n*10LL + (c-'0'); c=getc(stdin);}}
#define mod 1000000009
#define INF 10000000000000000LL
//Code starts here


void shortest_path(int s, vector<LL> &dist, const vector<vector<pair<int,LL>>> &G)
{
    auto cmp = 
        [&](const LL &a, const LL &b)
        {
            if(dist[a] == dist[b])
                return a < b;
            return dist[a] < dist[b];
        };

    int n = dist.size()-1;
    FORI(i,n) dist[i] = INF;
    dist[s] = 0;
    set<int,decltype(cmp)> Q(cmp);
    FORI(i,n) Q.insert(i);
    while(!Q.empty())
    {
        int v = *Q.begin();
        Q.erase(Q.begin());
        for(auto e : G[v])
        {
            int d = e.s;
            int w = e.f;
            if(dist[v] + d < dist[w])
            {
                Q.erase(w);
                dist[w] = dist[v]+d;
                Q.insert(w);
            }
        }
    }
}

vector<int> low;
vector<int> pre;
vector<int> par;
vector<bool> vis;
int counter;

void dfs_low(int v, int p, const vector<vector<int>> &G)
{
    vis[v] = true;
    pre[v] = counter;
    low[v] = counter;
    counter++;
    par[v] = p;
    //cout << v << endl;
    for(auto h : G[v])
    {
        if(h != p)
        {
            if(vis[h])
                low[v] = min(low[v], pre[h]);
            else
            {
                dfs_low(h,v,G);
                low[v] = min(low[v],low[h]);
            }
        }
    }
}

int main()
{
	IOS;
	//TEST("in.txt");
	int n,m,s,t,a,b;
    LL c;
	cin >> n >> m >>  s >> t;
	vector<vector<pair<int,LL>>> G(n+1);
    vector<vector<pair<int,LL>>> Gt(n+1);
	vector<pair<pair<int,int>,LL>> input;
	FOR(i,m)
	{
        cin >> a >> b >> c;
        input.PB(MP(MP(a,b),c));
        G[a].PB(MP(b,c));
        Gt[b].PB(MP(a,c));
	}

	
	vector<LL> src(n+1);
	vector<LL> dest(n+1);

	shortest_path(s,src,G);
	shortest_path(t,dest,Gt);

    //for(unsigned i = 1; i < src.size(); i++)
    //    cout << i << " : " << src[i] << endl;
    //cout << endl;
    //for(unsigned i = 1; i < dest.size(); i++)
    //    cout << i << " : " << dest[i] << endl;
    //cout << endl;

	vector<vector<int>> Gsp(n+1);
    
	FOR(i,m)
	{
        a = input[i].f.f;
        b = input[i].f.s;
        c = input[i].s;
        LL w = src[a]+dest[b];
        if(w+c==src[t])
        {
            Gsp[a].PB(b);
            Gsp[b].PB(a);
        }
	}
    pre.resize(n+1,0);
    vis.resize(n+1,false);
    low.resize(n+1,0);
    par.resize(n+1,0);
    counter = 1;

    dfs_low(s,0,Gsp);
    //FORI(i,n)
    //{
    //    cout << "i : " << i << ' ' << low[i] << ' ' << pre[i] << endl;
    //}

    map<pint,int> bridges;
    FOR(i,m)
    {
        a = input[i].f.f;
        b = input[i].f.s;
        c = input[i].s;
        LL w = src[a]+dest[b];
        //cout << a << ' ' << b << endl;
        if(w+c==src[t])
        {
           if(low[b] == pre[b] && par[b] == a)
               bridges[MP(a,b)]++;
        }
    }

    FOR(i,m)
    {
        a = input[i].f.f;
        b = input[i].f.s;
        c = input[i].s;
        LL w = src[a]+dest[b];
        //cout << a << ' ' << b << endl;
        if(w+c==src[t])
        {
            if(bridges[MP(a,b)] == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                if(c > 1)
                    cout << "CAN " << 1 << endl;
                else
                    cout << "NO" << endl;
            }
        }
        else
        {
            LL newC = (src[t]-w-1);
            if(newC > 0)
                cout << "CAN " << c-newC << endl;
            else
                cout << "NO" << endl;
        }
    }
	
}

