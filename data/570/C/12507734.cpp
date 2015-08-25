//Language: GNU C++11


#include <bits/stdc++.h>
#define REP(i,a,b) for (int i=a;i<=b;++i)
#define REPD(i,a,b) for (int i=a;i>=b;--i)
#define FOR(i,n) for (int i=0;i<n;++i)
#define X first
#define Y second
using namespace std;
const int N = 300010;
char s[N];
int n, m, l[N], r[N];
set<int> L, R;
int main()
{
    int d = 0;
    scanf("%d%d%s",&n,&m,s+1);
    l[0] = 0; l[n+1] = 0;
    REP(i,1,n) l[i] = (s[i]=='.') ? l[i-1]+1 : 0;
    r[n+1] = 0;
    REPD(i,n,1) r[i] = (s[i]=='.') ? r[i+1]+1 : 0;
    REP(i,1,n+1) if (l[i] == 0) d += max(0,l[i-1]-1);
    L.insert(0); L.insert(-n-1);
    R.insert(0); R.insert(n+1);
    REP(i,1,n) if (s[i] != '.') L.insert(-i), R.insert(i);
    int p, i, j, ans = d; char c;
    FOR(_,m) {
        scanf("%d%c",&p,&c); scanf("%c",&c);
        //ans = d;
        i = -*L.upper_bound(-p); j = *R.upper_bound(p);
        if (c == '.') {
            if (s[p] != '.') {
                ans -= max(0,j-p-2);
                ans -= max(0,p-i-2);
                ans += j-i-2;
                L.erase(L.find(-p)); R.erase(R.find(p));
            }
        }
        else if (s[p] == '.') {
            //i = -*L.upper_bound(-p); j = R.upper_bound(p);
            ans -= j-i-2;
            ans += max(0,j-p-2);
            ans += max(0,p-i-2);
            L.insert(-p); R.insert(p);
        }
        s[p] = c;
        printf("%d\n",ans);
    }
    return 0;
}
