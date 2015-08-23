//Language: GNU C++


#include <iostream>

using namespace std;
int votes[110];

int main() {
    int n, m, maxs, win, x;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        maxs = -1e9, win = -1;
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            if (x > maxs) {
                maxs = x;
                win = j;
            }
        }
        votes[win]++;
    }
    maxs = -1e9, win = -1;
    for (int i = 1; i <= n; ++i)
        if (votes[i] > maxs) {
                maxs = votes[i];
                win = i;
            }
    cout << win;
}
