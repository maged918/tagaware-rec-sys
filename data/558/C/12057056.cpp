//Language: GNU C++


/**
 *    @author     : Dipta Das
 *    @University : CUET CSE 11
 *    @Codeforces : diptadas
 *    @Topcoder   : dipta670
 *    @link       : www.fb.com/dipta.das
 */

#include <bits/stdc++.h>
using namespace std;

#define LL         long long
#define pll        pair<LL,LL>
#define mp         make_pair
#define fr         first
#define sc         second
#define pb         push_back

#define read(n)    scanf("%lld",&n)
#define mset(a,s)  memset(a,s,sizeof(a))
#define all(a)     a.begin(),a.end()

#define PI         acos(-1.0)
#define EPS        1e-9
#define MOD        1000000007
#define INF        1e9
#define NN         1000009

LL cnt[NN],b[NN],vis[NN];


int main()
{
    LL i,j,k,x,n;

    read(n);

    LL mx=0;

    for(i=0;i<n;i++)
    {
        read(b[i]);
        mx=max(b[i],mx);

    }

    mx*=2;

    for(i=0;i<n;i++)
    {
        x=b[i];
        for(j=0;x<=mx;j++)
        {
            cnt[x]+=j;
            vis[x]++;
            x*=2;
        }

        x=b[i];

        for(j=0;x>=1;j++)
        {
            cnt[x]+=j;
            vis[x]++;

            if(x%2 && x!=1)
            {
                LL xx=x-1;
                for(k=j+2;xx<=mx;k++)
                {
                    cnt[xx]+=k;
                    vis[xx]++;
                    xx*=2;
                }
            }

            x/=2;
        }

        vis[b[i]]--;
    }

    LL ans=INF;

    for(i=1;i<=mx;i++)
    {
        if(vis[i]==n)
            ans=min(ans,cnt[i]);
    }

    printf("%lld",ans);

    return 0;
}
