//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    vector<pair<int, int>> plus, minus;
   
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, a;
        cin >> x >> a;
        if (x < 0)
            minus.push_back(make_pair(-x, a));
        else
            plus.push_back(make_pair(x, a));
    }

    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());

    size_t m = min(minus.size(), plus.size());
    int ans = 0;
    for (int i = 0; i < min(m + 1, minus.size()); ++i)
        ans += minus[i].second;
    for (int i = 0; i < min(m + 1, plus.size()); ++i)
        ans += plus[i].second;

    cout << ans;
}