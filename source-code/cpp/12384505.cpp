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
#define hk push_back
#define pk pop_back
#define mp make_pair
#define PI 3.141592653589793
#define clr(a) memset(a, 0, sizeof(a))
#define clr1(a) memset(a, -1, sizeof(a))
typedef vector<int> VI;
typedef vector< pair<int, int> > VIP;
typedef vector< pair<int, pair<int, double> > > VIPP;
typedef vector<string> VS;
typedef vector <double> VD;
typedef vector <bool> VB;
typedef long long ll;
#define MAX_V 1000
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
    ll res = 1; a %= mod; for (; b; b >>= 1){ if (b & 1)res = res*a%mod; a = a*a%mod; }return res;
}

int n, k, a;
map<int, int> cnt;
map<int, int> cnt1;
map<int, int> cnt2;
VI input;

int main()
{
    cin >> n >> k;
    ll ret = 0;

    rep(i, 0, n) {
        cin >> a;
        input.push_back(a);
    }
    rep(i, 0, n) {
        int j = input[i];
        cnt[j]++;
        if (k == 1 || j == 0) cnt1[i] = cnt[j] - 1;
        else if ((j % k) == 0 && cnt.count(j)) cnt1[i] = cnt[j / k];
    }
    cnt.clear();
    per(i, n - 1, 0) {
        int j = input[i];
        cnt[j]++;
        
        ll idx = (ll)j * k;
        if (abs(idx) > 1000000000) continue;
        if (k == 1 || j == 0) cnt2[i] = cnt[j] - 1;
        else if (cnt.count(j * k)) cnt2[i] = cnt[j * k];
    }
    rep(i, 0, n) {
        ret += (ll)cnt1[i] * cnt2[i];
    }

    cout << ret << endl;

    return 0;
}