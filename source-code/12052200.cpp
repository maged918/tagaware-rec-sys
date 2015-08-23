//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
pair<int, int> p[105];
int main() {
    ios::sync_with_stdio(false);


    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, a;
        scanf("%d%d", &x, &a);
        p[i] = make_pair(x, a);
    }
    sort(p, p + n);

    int ans = 0;
    int ind = n - 1;
    for (int i = 0; i < n; i++)
        if (p[i].first > 0) {
            ind = i - 1;
            break;
        }

    int l = ind, r = ind + 1;
    int tmp = 0;
    while (true) {
        if (l < 0)
            break;
        tmp += p[l].second;
        --l;
        if (r >= n)
            break;
        tmp += p[r].second;
        ++r;
    }
    ans = max(ans, tmp);

    l = ind, r = ind + 1;
    tmp = 0;
    while (true) {
        if (r >= n)
            break;
        tmp += p[r].second;
        ++r;
        if (l < 0)
            break;
        tmp += p[l].second;
        --l;
    }
    cout << max(ans, tmp) << endl;






    return 0;
}

