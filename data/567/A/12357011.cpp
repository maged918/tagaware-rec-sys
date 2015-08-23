//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <utility>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

template <class T>
inline int RD(T &x) {
    x = 0;
    char ch = getchar();
    while(!isdigit(ch)) { ch = getchar();  if(ch == EOF) return 0; }
    while(isdigit(ch)) { x *= 10; x += ch - '0'; ch = getchar(); }
    return 1;
}

template <class T>
void PT(T a) {
     if(a > 9) PT(a / 10);
     putchar(a % 10 + '0');
}

typedef __int64 LL;
const int MAXN = 1e5 + 10;
LL d[MAXN], id[MAXN];
LL ans[MAXN][2];

bool cmp(LL a, LL b) {
    return d[a] < d[b];
}

LL ABS(LL x) {
    return x < 0 ? -x : x;
}

int main() {
//    freopen("A.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%I64d", d + i), id[i] = i;
    sort(id, id + n, cmp);
    ans[id[0]][0] = ABS(d[id[0]] - d[id[1]]);
    ans[id[0]][1] = ABS(d[id[0]] - d[id[n-1]]);
    ans[id[n-1]][0] = ABS(d[id[n-1]] - d[id[n-2]]);
    ans[id[n-1]][1] = ABS(d[id[n-1]] - d[id[0]]);
    for(int i = 1; i < n - 1; i++) {
        ans[id[i]][0] = min(ABS(d[id[i]] - d[id[i-1]]), ABS(d[id[i]] - d[id[i+1]]));
        ans[id[i]][1] = max(ABS(d[id[i]] - d[id[n-1]]), ABS(d[id[i]] - d[id[0]]));
    }
    for(int i = 0; i < n; i++)
        printf("%I64d %I64d\n", ans[i][0], ans[i][1]);
    return 0;
}
