//Language: GNU C++11


//
//  Created by TaoSama on 2015-08-11
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long B[4010][4010];
int n;

void gao() {
    B[1][1] = 1;
    B[2][1] = 1;
    B[2][2] = 2;
    for(int i = 3; i < 4010; i++) {
        for(int j = 1; j < 4010; j++) {
            if(j == 1)
                B[i][j] = B[i - 1][i - 1];
            else
                B[i][j] = (B[i][j - 1] + B[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(cin >> n) {
        cout << B[n + 1][n] << '\n';
    }
    return 0;
}
