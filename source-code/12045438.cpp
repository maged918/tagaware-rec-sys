//Language: GNU C++11


#include <bits/stdc++.h>

typedef long long int64;
#define sz(A) (int((A).size()))

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);
    const int maxn = 1000 * 1000 + 10;
    vector <int> cnt(maxn), left(maxn, INT_MAX), right(maxn, INT_MIN);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        left[a[i]] = min(left[a[i]], i);
        right[a[i]] = max(right[a[i]], i);
    }
    int maxcnt = *max_element(cnt.begin(), cnt.end());
    int resl = -1, resr = -1;

    for (int i = 0; i < maxn; i++)
    {
        if (cnt[i] == maxcnt && (resl == -1 || resr - resl > right[i] - left[i]))
        {
            resl = left[i];
            resr = right[i];
        }
    }
    cout << resl + 1 << ' ' << resr + 1 << '\n';

    return 0;
}
