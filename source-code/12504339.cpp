//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int fr[105];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("date.in","r",stdin);
        freopen("date.out","w",stdout);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    swap(n,m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int maax=-1,poz=0;
    for(int i=1;i<=n;i++)
    {
        maax=-1;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]>maax)
            {
                maax=a[i][j];
                poz=j;
            }
        }
        fr[poz]++;
    }
    maax=-1;
    for(int i=1;i<=m;i++)
    {
        if(maax<fr[i])
            maax=fr[i];
    }
    for(int i=1;i<=m;i++)
        if(maax==fr[i])
        {
            cout<<i;
            break;
        }
    return 0;
}
