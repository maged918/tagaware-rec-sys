//Language: GNU C++11


#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int const N = 101;
int mx, n, ans, m;
set <int> a;
char ch;
int main() {
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch >> m;
        if (ch == '+') a.insert(m), mx++;
        else if (a.count(m)) mx--, a.erase(m);
            else ans++;
            ans = max(ans, mx);
    }
    printf("%d\n", ans);
    return 0;
}
