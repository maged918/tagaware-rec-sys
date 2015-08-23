//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define MAX 200005

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, i, mn, mx, a[MAX];

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
    {
        mn = 2000000000;
        mx = 0;

        if(i > 0)
            mn = a[i]-a[i-1];
        if(i+1 < n)
            mn = min(mn, a[i+1]-a[i]);
        mx = max(a[i]-a[0], a[n-1]-a[i]);

        cout << mn << " " << mx << "\n";
    }

    return 0;
}


