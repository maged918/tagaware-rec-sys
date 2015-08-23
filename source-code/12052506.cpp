//Language: GNU C++11


#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int x,a;
}tr[105];

bool cmp(tree a,tree b)
{
    return a.x<b.x;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&tr[i].x,&tr[i].a);
    int ans=0;
    sort(tr,tr+n,cmp);
    int po[105];
    for(i=0;i<n;i++)po[i]=tr[i].x;
    int l=lower_bound(po,po+n,0)-po;
    int r=n-l;
    if(r>l)
    {
        int len=l*2+1;
        for(i=0;i<len;i++)
            ans+=tr[i].a;
    }
    else if(r==l)
    {
        for(i=0;i<n;i++)
            ans+=tr[i].a;
    }
    else
    {
        int len=r*2+1;
        for(i=n-1;i>n-r*2-2;i--)
            ans+=tr[i].a;
    }
    printf("%d",ans);
    return 0;
}
