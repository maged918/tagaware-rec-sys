//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k; long a,b; int c[101];
int main()
{
    cin>>n>>m;
    memset(c,0,sizeof(c));
    for(i=1;i<=m;++i)
    {
        b=-1;
        for(j=1;j<=n;++j)
        {
            cin>>a;
            if (a>b)
            {
                b=a; k=j;
            }
        }
        ++c[k];
    }
    a=-1;
    for(i=1;i<=n;++i)
    if (c[i]>a)
    {
        j=i; a=c[i];
    }
    cout<<j;
}