//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int d[4007][4007],n,v=1e9 + 7, i, j;
int main() {
    cin >> n;
    d[1][1] = 1;
    for (i = 2; i < n + 2; i++) {
        d[i][1]=d[i-1][i-1];
        for (j = 2; j <= i; j++)
            d[i][j] = (d[i][j-1]+d[i-1][j-1])%v;
    }
    cout << d[n + 1][n];
}