//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cassert>
#define LL long long
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8
//using namespace std;
typedef std::pair<int,int> pii;
const int Mod = 1e9 + 7;
const int MaxN = 200001;

int w, h, n;
int fac[MaxN], inv[MaxN], fac_inv[MaxN];
std::vector<pii> blacks;
int dp[2222];



void init(){
    fac[0] = fac[1] = 1; inv[0] = inv[1] = fac_inv[1] = fac_inv[0] = 1;
    for(int i = 2; i < MaxN; ++i){
        fac[i] = 1LL * fac[i - 1] * i % Mod;
        inv[i] = 1LL * (Mod - Mod / i) * inv[Mod % i] % Mod;
        fac_inv[i] = 1LL * fac_inv[i - 1] * inv[i] % Mod;
    }
}

int comb(int n, int m){
    return 1LL * fac[n] * fac_inv[m] % Mod * fac_inv[n - m] % Mod;
}

int main(){
    init();
    scanf("%d%d%d", &h, &w, &n);
    for(int i = 0, x, y; i < n; ++i){
        scanf("%d%d", &x, &y);
        blacks.push_back(pii(x, y));
    }
    blacks.push_back(pii(h, w));
    std::sort(blacks.begin(), blacks.end());
    for(int i = 0; i < n + 1; ++i){
        int tmp = comb(blacks[i].first + blacks[i].second - 2, blacks[i].second - 1);
        for(int j = 0; j < i; ++j) if(blacks[j].first <= blacks[i].first && blacks[j].second <= blacks[i].second){
            int nn = blacks[i].first - blacks[j].first + blacks[i].second - blacks[j].second;
            int mm = blacks[i].first - blacks[j].first;
            tmp = (tmp - 1LL * dp[j] * comb(nn, mm) % Mod + Mod) % Mod;
        }
        dp[i] = tmp;
    }
    printf("%d\n", dp[n]);
    return 0;
}
