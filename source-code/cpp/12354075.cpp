//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

long long x[100005];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cout << x[1] - x[0] << " " << x[n-1] - x[0] << endl;
    for(int i = 1; i < n - 1; i++)
        cout << min(x[i] - x[i-1], x[i+1] - x[i]) << " " << max(x[i] - x[0], x[n-1] - x[i]) << endl;
    
    cout << x[n-1] - x[n-2] << " " << x[n-1] - x[0] << endl;
    return 0;
}
