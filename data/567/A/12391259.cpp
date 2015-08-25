//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d %d\n",a[1]-a[0],a[n-1]-a[0]);
    for(int i=1;i<n-1;i++)
        printf("%d %d\n",min(a[i+1]-a[i],a[i]-a[i-1]),max(a[n-1]-a[i],a[i]-a[0]));
    printf("%d %d\n",a[n-1]-a[n-2],a[n-1]-a[0]);
    return 0;
}