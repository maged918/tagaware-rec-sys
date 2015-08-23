//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
#define M 100005
using namespace std;

struct line{
    LL l,r;
}L[M<<1];

bool cmp(struct line a,struct line b)
{
    return a.l<b.l;
}

LL solve(LL a,int k)
{
    for (int i=0;i<k;i++)
        a=a*2+1;
    return a;
}

int main()
{
    int q,h,k,i,cnt,f;
    LL c1[55],l,r,ans,t;
    for (c1[0]=i=1;i<=50;i++)
        c1[i]=c1[i-1]<<1;
    while (scanf("%d%d",&h,&q)!=EOF)
    {
        for (cnt=i=0;i<q;i++)
        {
            scanf("%d%I64d%I64d%d",&k,&l,&r,&f);
            if (f){
                if (l>c1[k-1])
                    L[cnt].l=c1[h-1],L[cnt++].r=solve(l-1,h-k);
                if (r<c1[k]-1)
                    L[cnt].l=(r+1)*c1[h-k],L[cnt++].r=c1[h]-1;
            }
            else{
                L[cnt].l=l*c1[h-k];
                L[cnt++].r=solve(r,h-k);
            }
        }
        sort(L,L+cnt,cmp);
        if (L[0].l>c1[h-1]+1)
            printf("Data not sufficient!\n");
        else {
            r=L[0].r;
            ans=c1[h-1];
            t=L[0].l>c1[h-1];
            for (i=0;i<cnt&&t<2;i++)
            {
                if (L[i].l<=r||L[i].l-1==r)
                    r=max(r,L[i].r);
                else if (L[i].l-r>2)
                {t=2;break;}
                else t++,ans=r+1,r=L[i].r;
            }
            if (c1[h]-1>r)
                t+=c1[h]-1-r,ans=c1[h]-1;
            if (t>1)
                printf("Data not sufficient!\n");
            else if (t==0)
                printf("Game cheated!\n");
            else printf("%I64d\n",ans);
        }
    }
    return 0;
}
