//Language: GNU C++11


#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, pair<int, long long int>> h;

int main() {
    int n, k;
    long long int result = 0;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x, add = 0;
        cin >> x;


        if (x % k == 0) {
            auto it2 = h.find(x / k);
            if (it2 != h.end()) {
                add += it2->second.first;
                result += it2->second.second;
            }
        }

        auto it = h.find(x);
        if (it == h.end())
            it = h.insert({x, {1, add}}).first;
        else {
            ++it->second.first;
            it->second.second += add;
        }
    }

    cout << result << '\n';

    return 0;
}
