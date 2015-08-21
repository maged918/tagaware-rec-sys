//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100005] = {0}, ans[100005] = {0};
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        ans[a[i]]++;
    }
    int cnt = 1;

    for(int i=0; i<n; i++) {
        while(ans[cnt]) cnt++;
        if(ans[a[i]] > 1 || a[i] > n) {
            ans[cnt]++;
            ans[a[i]]--;
            a[i] = cnt;
        }
    }

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
