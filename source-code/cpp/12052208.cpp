//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int M = 26;

int dd[MAXN*4], it[M][MAXN*4], tmp[M];

int N, Q;

void update(int u, int v, int l, int r, int k, int c)
{
    if (u>v||u>r||v<l) return;
    if (u<=l&&v>=r)
    {
        dd[k]=c;
        for(int i=0; i<M; i++) it[i][k]=0;
        it[c][k]=r-l+1;
        return;
    }
    int mid = (l+r) /2;
    if (dd[k]!=-1)
    {
        update(l,mid,l,mid,(k<<1),dd[k]);
        update(mid+1,r,mid+1,r,(k<<1)+1,dd[k]);
        dd[k]=-1;
    }
    update(u,v,l,mid,(k<<1),c);
    update(u,v,mid+1,r,(k<<1)+1,c);
    for(int i=0; i<M; i++) it[i][k]=it[i][(k<<1)]+it[i][(k<<1)+1];
}

void nhap()
{
    scanf("%d%d\n",&N,&Q);
    memset(dd,255,sizeof(dd));
    memset(it,0,sizeof(it));
    for(int i=1; i<=N; i++)
    {
        char c = getchar();
        update(i,i,1,N,1,c-'a');
    }
}

int giao(int u, int v, int l, int r)
{
    return min(v,r)-max(u,l)+1;
}

int get(int u, int v, int l, int r, int k, int c)
{
    if (u>v||u>r||v<l) return 0;
    if (dd[k]!=-1)
    {
        if (dd[k]==c)
            return giao(u,v,l,r);
        else return 0;
    }
    if (u<=l&&v>=r)
    {
        return it[c][k];
    }
    int mid = (l+r)/2;
    int t1 = get(u,v,l,mid,(k<<1),c);
    int t2 = get(u,v,mid+1,r,(k<<1)+1,c);
    return (t1+t2);
}

void truyv()
{
    while (Q--)
    {
        int u, v, k;
        scanf("%d%d%d",&u,&v,&k);
        memset(tmp,0,sizeof(tmp));
        for(int i=0; i<M; i++)
            tmp[i]=get(u,v,1,N,1,i);
        if (k==1)
        {
            for(int i=0; i<M; i++)
            {
                update(u,u+tmp[i]-1,1,N,1,i);
                u+=tmp[i];
            }
        } else
        {
            for(int i=M-1; i>=0; i--)
            {
                update(u,u+tmp[i]-1,1,N,1,i);
                u+=tmp[i];
            }
        }
    }
}

void xuat()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<M; j++)
        {
            int t = get(i,i,1,N,1,j);
            if (t==1)
            {
                printf("%c",j+'a');
                break;
            }
        }
    }
}

int main()
{
    nhap();
    truyv();
    xuat();
    return 0;
}
