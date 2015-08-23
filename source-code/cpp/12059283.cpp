//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int a[100005];
int f(int a,int b)
{
    return a==b?a:f(min(a,b),max(a,b)/2);
}
int cal(int a,int b)
{
    return a==b?0:cal(min(a,b),max(a,b)/2)+1;
}
int main()
{
    //freopen("c.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)) {
        int g;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            if(i==1) {
                g=f(a[i],a[i]);
            }
            else {
                g=f(g,a[i]);
            }
        }
        int ans=1e9;
        for(int i=g;i<=100000;i*=2) {
            int tans=0;
            for(int j=1;j<=n;j++) {
                tans+=cal(i,a[j]);
            }
            ans=min(ans,tans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
