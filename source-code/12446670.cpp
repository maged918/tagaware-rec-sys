//Language: GNU C++


#include <bits/stdc++.h>
#define filein(t) freopen(t, "r", stdin)
#define fileout(t) freopen(t, "w", stdout)
#define ll long long
#define rep(i,n) for(int i=0; i<n; i++)
#define mp make_pair
#define CS 1117
#define f first
#define s second
#define N 100005
#define BIT(i, n) ( (n >> i) & 1 )
#define ln 100000000000000008
#define oo 1000000007

using namespace std;

int a[N], n, dd[N], S[N], top, ok[N];

int main()
{
    ios_base::sync_with_stdio(0);
   // filein("inp.txt");
   // fileout("out.txt");
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(dd[a[i]] == 0 && a[i] <= n) ok[i] = 1;
        dd[a[i]]++;
    }
    for(int i=1; i<=n; i++)
        if(dd[i] == 0)
            S[++top] = i;
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(ok[i] == 0)
            cout << S[++cnt] << " ";
        else
            cout << a[i] << " ";
    }
}
