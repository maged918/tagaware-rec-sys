//Language: MS C++


#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <utility>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vi> vvi; 
typedef vector<vl> vvl; 
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;

typedef vector<int>::iterator vi_it;
typedef vector<long>::iterator vl_it;
typedef vector<ll>::iterator vll_it;

typedef set<int> si;
typedef set<long> sl;
typedef set<char> sc;
typedef set<int>::iterator si_it;
typedef set<long>::iterator sl_it;
typedef set<string> ss;
typedef set<char> sc;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<pii>::iterator vpii_it;
typedef pair<long,long> pll;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<string,long> msl;
typedef map<string,int> msi;
typedef map<long,long> mll;
typedef vector<mll> vmll;
typedef map<char,int> mci;
typedef vector<mci> vmci;
typedef vector<msi> vmsi;
typedef map<char,long> mcl;
typedef pair<char,long> pcl;
typedef vector<pcl> vpcl;

#define sz(a) int((a).size()) 
#define sl(a) int((a).length()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).rbegin(),(c).rend() 
#define tr(container, it) for (auto it = container.begin(); it != container.end(); it++) 
#define exist(c,x) ((c).find(x) != (c).end()) 
#define existv(c,x) (find(all(c),x) != (c).end())
#define loc(c,x) ((c).find(x) - (c).begin()) 
#define locv(c,x) (find(all(c),x) - (c).begin())
#define wl(x) (cout << (x) << endl)
#define w(x) (cout << (x))
#define r(x) (cin >> x);
#define FOR(i,a,b) for (auto i = (a); i < (b); i++)
#define RFOR(i,a,b) for (auto i = (a); i > (b); i--)
#define PP(x) tr(x,it) cout << it->first << " " << it->second << endl
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second

const ll mod=1000000007;
vll fact(200001);
ll powmod(ll a,ll b) { ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res; }
ll go(ll x, ll y) { return 1ll * fact[x+y] * powmod(1ll * fact[x] * fact[y], mod - 2) % mod; }

// target = (cond) ? true_case : false_case
//std::string::size_type i = t.find(s);
//if ((size_type i = s.find("144")) != string::npos) s.erase(i, 3);
// while ((i = s.find("144")) != string::npos) s.erase(i, 3);
//std::string binary = std::bitset<16>(1561561654).to_string(); //to binary
//std::string binary = std::bitset<8>(123).to_string(); //to binary
//unsigned long decimal = std::bitset<8>(binary).to_ulong();
//string::size_type sz; c=stol(a,&sz);
//bool is_b_exists_in_a(string a, string b){long x=0;FOR(i,(long)0,sz(a)) if (a[i] == b[x]) { x++; if (x==sz(b)) return true; }return false;}
//string::iterator low;
//bool is_palindrome(string s){long sl=s.length();  FOR(i,(long)0,sl/2) if (s[i] != s[sl-1-i]) return false;    return true;}

int main() {
long h,w;
int n;

    //FILE *in, *out;freopen_s(&in, "in.txt", "r", stdin);freopen_s(&out, "out.txt", "w", stdout);
    
    r(h);r(w);r(n);
    vpll x(n+2);
    FOR(i,0,n) { r(x[i].first); r(x[i].second); }
    x[n++] = mp(1,1);
    x[n++] = mp(h,w);
    sort(all(x));
    //PP(x);
    fact[0] = 1;
    FOR(i,1,h+w+1) fact[i]=i*fact[i-1]%mod;
    //tr(fact,it) wl(*it);
    vll dp(n);
    dp[0] = 1;
    FOR(i,1,n)
    {
        dp[i] = go(x[i].fi-1, x[i].se-1);
        FOR(j,1,i)
            if (x[j].fi <= x[i].fi && x[j].se <= x[i].se)
                dp[i] = (dp[i] - go(x[i].fi - x[j].fi, x[i].se - x[j].se) * dp[j]) % mod;
    }
    dp[n-1] = (dp[n-1] + mod) % mod;
    wl(dp[n-1]);

    return 0;
}
