//Language: GNU C++11


#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> Vint;
#define pb push_back
#define mp make_pair
typedef long double ld;

int ispower(int val)
{
    return __builtin_popcount(val) == 1;
}

void solve(int n)
{
    Vint v(n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);

    const int bound = (int)1e6;
    Vint interes;
    const int inf = (int)1e9;
    int ans = inf;

    int x = v[0];
    while (x >= 0)
    {
        interes.pb(x);
        if (x == 0)
            break;

        for (int i = x; i <= bound; i *= 2)
            interes.pb(i);
        x /= 2;
    }

    sort(interes.begin(), interes.end());
    interes.resize(unique(interes.begin(), interes.end()) - interes.begin());

    for (int need : interes)
    {
        int cur = 0;
        if (need == 0)
        {
            for (int i = 0; i < n; i++)
            {
                int x = v[i];
                while (x > 0)
                    cur++, x /= 2;
            }
            ans = min(ans, cur);
            continue;
        }

        for (int i = 0; i < n;  i++)
        {
            int x = v[i];
            while (x != 0 && (!ispower(need / x) || need % x != 0))
                x /= 2, cur++;
            if (x == 0)
            {
                cur = inf;
                break;
            }
            if (cur > ans)
                break;

            assert(ispower(need / x) && need % x == 0);
            while (x != need)
                x *= 2, cur++;
        }

        ans = min(ans, cur);
    }

    cout << ans << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    while (cin >> n)
        solve(n);
}
