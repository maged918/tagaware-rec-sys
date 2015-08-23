//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define maxn 4444
long long s[maxn][maxn];
const long long mod=1e9+7;
void init()
{
    memset(s,0,sizeof(s));
    s[1][1]=1;
    for(int i=2; i<=maxn-1; i++)
        for(int j=1; j<=i; j++)
        {
            s[i][j]=s[i-1][j-1]+j*s[i-1][j];
            if(s[i][j]>=mod)
                s[i][j]%=mod;
        }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long ans=0;
        for(int i=1; i<=n; i++)
        {
            ans+=s[n][i]*i;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
