//Language: GNU C++11


#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

int a[111][111];
int v[111];

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m; cin >> n >> m;

    int res = 0;

    for (int i = 0; i < m; i++) {
        int best = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] > a[i][best]) {
                best = j;
            }
        }
        v[best]++;
    }

    for (int i = 1; i < n; i++) {
        if (v[i] > v[res]) {
            res = i;
        }
    }

    cout << res + 1 << endl;

    return 0;
}
