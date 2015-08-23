//Language: MS C++


#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <ctime>
#pragma warning (disable : 4996)

using namespace std;

#define MP make_pair
#define lli long long int

const int N = 2e6 + 10;
const int M = 1e9 + 7;

char s[N];

int main() {
#ifdef FILE_IO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    gets(s);
    gets(s);
    int ans = 0;
    for (int i = 1; i < n; ++i) ans += s[i] == s[i - 1] && s[i] == '.';
    for (int i = 0; i < m; ++i) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        if (s[p] == '.' && c != '.') ans -= (p && s[p - 1] == '.') + (p + 1 < n && s[p + 1] == '.');
        if (s[p] != '.' && c == '.') ans += (p && s[p - 1] == '.') + (p + 1 < n && s[p + 1] == '.');
        s[p] = c;
        cout << ans << endl;
    }
}