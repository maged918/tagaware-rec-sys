//Language: GNU C++



#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <stack>
#include <complex>
#define REP(i,n) for(int i=0;i<n;i++)
#define ESP 1e-11
using namespace std;
typedef long long int ll;

vector<ll> kai(200005);
vector<ll> inv(200005);
const ll mod = 1000000007;

ll power(ll a, ll p){
    ll res = 1;
    while(p>0){
        if(p & 1) res *= a;
        if(res >= mod) res %= mod;
        a *= a;
        if(a >= mod)a %= mod;
        p >>= 1;
    }
    return res;
}

ll comb(ll a,ll b){
    ll ret = kai[a+b];
    ret *= inv[a];
    if(ret>=mod) ret %= mod;
    ret *= inv[b];
    if(ret>=mod) ret %= mod;
    return ret;
}

int main(){
    kai[0]=1;
    kai[1]=1;
    inv[0]=1;
    inv[1]=1;
    for (int i=2; i<kai.size(); i++) {
        kai[i]=kai[i-1]*i;
        if(kai[i]>=mod) kai[i]%=mod;
        inv[i]=power(kai[i], mod-2);
    }
    vector<pair<int, int> > black;
    int h,w,n;
    cin >> h >> w >> n;
    for (int i=0; i<n; i++) {
        int y,x;
        cin >> y >> x;
        black.push_back({y-1,x-1});
    }
    black.push_back({h-1,w-1});
    sort(black.begin(),black.end());
    vector<ll> dp(black.size());
    for (int i=0; i<black.size(); i++) {
        dp[i] = comb(black[i].first, black[i].second);
        int temp = i;
        while(temp>0){
            temp--;
            if(black[temp].second<=black[i].second){
                ll minus = dp[temp]*comb(black[i].first-black[temp].first,black[i].second-black[temp].second);
                minus %= mod;
                dp[i] = (dp[i]-minus+mod)%mod;
            }
        }
    }
    cout << dp[black.size()-1]<<endl;
}