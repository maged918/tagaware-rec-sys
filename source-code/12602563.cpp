//Language: MS C++


#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <intrin.h>
//#include <unordered_set>
#include <fstream>
#include <map>
#include <sstream>
//#include <unordered_map>
#include <random>
#include <stack>
//#include <stdio.h>
#include <algorithm>
#include <cmath>

//#include <ctime>

using namespace std;
#define ll long long
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)
#define PI 3.1415926535
#define EPS 0.00000001
#define pii pair<int, int>
const ll INF = 1000000002ll * 1000000002ll;

#define DEBUG 41

#ifndef DEBUG

ifstream in("input.in");
ofstream out("output.out");

#define cin in
#define cout out

#endif
vector<vector<int> > g;
vector<vector<int> > in;
vector<vector<int> > out;
vector<vector<int> > sum;
int h[1244567];
pii a[1244567];
int timer;
string s;

void dfs(int v, int p)
{
    h[v] = p;
    a[v].first = timer++;
    for(int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        dfs(to, p+1);
    }
    a[v].second = timer++;
    in[p].push_back(a[v].first);
    out[p].push_back(a[v].second);
    if(sum[p].size() == 0)
        sum[p].push_back(1<< (s[v-1]-'a'));
    else
        sum[p].push_back(sum[p].back() ^ (1<<(s[v-1]-'a')));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*vector<int> vvv;
    vvv.push_back(1);
    vvv.push_back(3);
    vvv.push_back(5);
    cout << upper_bound(vvv.begin(), vvv.end(), 1) - vvv.begin();*/
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    sum.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
    for(int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    cin >> s;
    dfs(1,1);
    for(int i = 0; i < m; ++i)
    {
        int w, c;
        cin >> w >> c;
        if(h[w] >= c)
        {
            cout << "Yes\n";
            continue;
        }

        int l = lower_bound(in[c].begin(), in[c].end(), a[w].first) - in[c].begin();
        int r = lower_bound(out[c].begin(), out[c].end(), a[w].second) - out[c].begin();
        if(l == in[c].size())
        {
            cout << "Yes\n";
            continue;
        }
        --r;
        if(r < 0)
        {
            cout << "Yes\n";
            continue;
        }
        int ss;
        if(l == 0)
            ss = sum[c][r];
        else
            ss = sum[c][r] ^ sum[c][l-1];

        if(__popcnt(ss) > 1)
            cout << "No\n";
        else
            cout << "Yes\n";

    }

    return 0; 

}

/*
10 10
aaaaaaaaaa
1 .
2 .
10 .
9 .
4 .
3 .


*/