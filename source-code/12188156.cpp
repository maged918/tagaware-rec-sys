//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;
string s, t;
int d = 26, mod = 1e9 + 7;
bool solve(int l1, int r1, int l2, int r2)
{
    long long h1 = 0, h2 = 0;
    for(int i = l1; i <= r1; i++)
        h1 = (h1 * d + s[i] - 'a') % mod;
    for(int i = l2; i <= r2; i++)
        h2 = (h2 * d + t[i] - 'a') % mod;
    if(h1 == h2)
        return 1;
    else if((r1 - l1 + 1) % 2 == 1)
        return 0;
    else
    {
        int sz1 = r1 - l1 + 1, sz2 = r2 - l2 + 1;
        return (solve(l1, l1 + sz1/2 - 1, l2 + sz2/2, r2) && solve(l1 + sz1/2, r1, l2, l2 + sz2/2 - 1) || solve(l1, l1 + sz1/2 - 1, l2, l2 + sz2/2 - 1) && solve(l1 + sz1/2, r1, l2 + sz2/2, r2));
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    if(s == t)
        cout << "YES";
    else if(s.size() % 2 == 1)
        cout << "NO";
    else
    {
        if(solve(0, s.size() - 1, 0, s.size() - 1))
        {
            cout << "YES";
        }
        else
            cout << "NO";
    }
    return 0;
}
