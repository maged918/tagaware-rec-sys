//Language: GNU C++11


#include <bits/stdc++.h>

#define maxn 100005
#define maxc 1000006
#define reset(a) memset(a,0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fi freopen("a.inp","r",stdin)
#define fo freopen("a.out","w",stdout)

using namespace std;

int n,dd[maxc],dem = 0,maxx = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    reset(dd);
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        char t;
        int x;
        cin >> t >> x;
        if(t == '-' && !dd[x])
        {
            maxx++;
            continue;
        }
        if(t == '-' && dd[x]) dem--;
        if(t == '+')
        {
            dem++;
            dd[x] = 1;
        }
        maxx = max(dem,maxx);
    }
    cout << maxx;
}
