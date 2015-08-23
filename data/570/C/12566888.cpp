//Language: GNU C++11


/*
 #include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int x = m + 1, y = m - 1;
    if (y == 0 && x == n + 1) {
        cout << 1;
        return 0;
    }
    if (y == 0 || x <= n && (n - x + 1) > y) {
        cout << x;
    } else {
        cout << y;
    }
    return 0;
}
316.2.B */

#include <iostream>
using namespace std;
int main()
{
    int n, q, r = 0;
    cin >> n >> q;
    string S;
    cin >> S;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && S[j] == '.') {
            ++j;
        }
        if (j - i >= 2) {
            r += (j - i - 1);
        }
        i = j;
    }
    for (int i = 0; i < q; ++i) {
        char c;
        int k;
        cin >> k >> c;
        if (c == '.' && S[k - 1] != '.') {
            r += 2;
            if (k == 1 || S[k - 2] != '.') {
                --r;
            }
            if (k == n || S[k] != '.') {
                --r;
            }
        }
        if (c != '.' && S[k - 1] == '.'){
            r -= 2;
            if (k == 1 || S[k - 2] != '.') {
                ++r;
            }
            if (k == n || S[k] != '.') {
                ++r;
            }
        }
        S[k - 1] = c;
        cout << r << "\n";
    }
    return 0;
}
