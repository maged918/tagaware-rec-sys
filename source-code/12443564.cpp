//Language: GNU C++


using namespace std;
#include<bits/stdc++.h>
#define FOR(i,a,b) for (long long i=a;i<b;i++)
#define FORE(i,a,b) for (long long i=a;i<=b;i++)
#define FORD(i,a,b) for (long long i=a;i>=b; i--)

int n, a[1000000], dd[1000000], pos[1000000 +10],b[1000000 +10];
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin>>n;
    int m = 0;
    memset(pos, 0, sizeof(pos));
    FORE(i, 1, n) cin>>a[i], pos[a[i]] = i;
    memset(dd, 0, sizeof(dd));
    FORE(i, 1, n) if (pos[i] == 0) b[++m] = i;
        else dd[pos[i]] = 1;
    int j = 0;
    FORE(i, 1, n) if (dd[i] == 0) a[i] = b[++j];
    FORE(i, 1, n) cout<<a[i]<< " ";
    return 0;
}
