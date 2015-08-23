//Language: GNU C++11


#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), b(n+100);

    for (int i = 0; i  < n; ++i) {
        cin >> v[i];
        if (v[i] >= 1 && v[i] <= n && !b[v[i]]) {
            b[v[i]] = 1;
        }
    }

    vector<int> notused;
    for (int i = 1; i <= n; ++i) {
        if (!b[i]) {
            notused.push_back(i);
        }
    }

    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] < 1 || v[i] > n || !b[v[i]])
            v[i] = notused[idx++];
        else
            b[v[i]] = 0;
        cout << v[i];
        if (i == n-1)
            cout << endl;
        else
            cout << " ";
    }

    return 0;
}
