//Language: GNU C++11


#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000002];
int bosh[1000002];
int tamom[1000002];
int x[100002];
main()
{
    ios::sync_with_stdio(false);
    int n, m = 1e6, i, j, l, r, uz = 1e7, s = 0;
    cin >> n;
    for(i = 1; i <= n; i ++)
    {
        cin >> x[i];
        a[x[i]] ++;
        s = max(s, a[x[i]]);
        if(!bosh[x[i]])
        {
            bosh[x[i]] = i;
        }
        tamom[x[i]] = i;
    }
    for(i = 1; i <= n; i ++)
    {
        if(a[x[i]] == s)
        {
            if(uz > tamom[x[i]] - bosh[x[i]] + 1)
            {
                l = bosh[x[i]];
                r = tamom[x[i]];
                uz = tamom[x[i]] - bosh[x[i]] + 1;
            }
        }
    }
    cout << l << " " << r << endl;
}
