//Language: GNU C++11


#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    long long x, a, n; cin >> n;
    vector<vector<long long>> v(n);
    for(int i = 0; i<n; i++) {
        cin >> x >> a;
        v[i].push_back(x);
        v[i].push_back(a);
    }
    sort(v.begin(), v.end());
    long long i;
    for(i=0; i<n && v[i][0]<0; i++);
    long long sum=0;
    long long left = i, right=n-i;
    //cout << left << " " << right;
    long long can_get = min(left, right)+1;
    for(int j=i-can_get; j<i+can_get; j++) {
        if(j>=0 && j<n) {
            sum+=v[j][1];
        }
    }
    cout << sum << "\n";
}