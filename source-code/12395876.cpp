//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> l, r;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r[arr[i]]++;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long x = arr[i];
        r[x]--;
        if (x % k == 0 && x * k <= 1e9 && x * k >= -1e9)
            res += (long long)l[x / k] * r[x * k];
        l[x]++;
    }
    cout << res << endl;
    return 0;
}
