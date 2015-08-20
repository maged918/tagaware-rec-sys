//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int vis[1000005],l[1000005],r[1000005],a[10000005];
int main()
{
  int maxx,minl,minr,minx,i,n;
  scanf("%d",&n);
  memset(vis,0,sizeof(vis));
  memset(l,0,sizeof(l));
  memset(r,0,sizeof(r));
  maxx=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    vis[a[i]]++;
    maxx=max(maxx,vis[a[i]]);
    if (l[a[i]]==0) l[a[i]]=i;
    r[a[i]]=i;
  }
  minx=n; minl=1; minr=n;
  for (i=1;i<=n;i++)
    if (l[a[i]]==i&&vis[a[i]]==maxx&&r[a[i]]-l[a[i]]+1<minx)
    {
      minx=r[a[i]]-l[a[i]];
      minl=l[a[i]]; minr=r[a[i]];
    }
  printf("%d %d\n",minl,minr);
}
