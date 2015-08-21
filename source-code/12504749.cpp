//Language: GNU C++


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<string>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<utility>
#include<numeric>
#include<iomanip>
#include<complex>
#include<valarray>
using namespace std;
typedef long long int ll;
typedef unsigned int u32;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;
typedef pair <int, int > pii;
ll Gcd(ll a, ll b){ while (a %= b ^= a ^= b ^= a);  return b; }
#define SQR(x) ((x)*(x))
#define all(v) (v.begin()),(v.end())
#define sz(v)  ((int)((v).size()))
#define For(i,start,end) for(int i=start;i<end;++i)


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vi v,res;
    int n, m,vote;
    cin >> n >> m;
    v.resize(n); res.resize(n,0);
    For(i, 0, m)
    {
        int Max = -99999999;
        For(j, 0, n)
        {
            cin >> v[j];
            if (v[j] > Max)
            {
                Max = v[j];
                vote = j;
            }
        }
        res[vote]++;
    }
    int Max = -9999999;
    For(i, 0, sz(res))
    {
        if (res[i] > Max)
        {
            Max = res[i];
            vote = i + 1;
        }
    }
    cout << vote << endl;

    
    return 0;
}