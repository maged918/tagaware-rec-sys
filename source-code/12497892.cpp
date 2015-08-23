//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (m - 1 >= n - m) {
        cout << m - 1 << endl;
    } else {
        cout << m + 1 << endl;
    }
}
