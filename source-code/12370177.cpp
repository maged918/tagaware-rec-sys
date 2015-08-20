//Language: GNU C++11


#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lson l,mid,o<<1
#define rson mid + 1,r,o<<1|1
using namespace std;
typedef __int64 LL;
const int maxn = 200005;
int a[maxn],sum[maxn<<2];
int n,m,k;
int A,B;
void update(int l,int r,int o)
{
    if(l == r)
    {
        sum[o] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(A <= mid) update(lson);
    else update(rson);
    sum[o] = sum[o<<1] + sum[o<<1|1];
}
int qurry(int l,int r,int o)
{
    if(A <= l && r <= B)
    {
        return sum[o];
    }
    int mid = (l + r) >> 1;
    int ans = 0;
    if(A <= mid) ans += qurry(lson);
    if(B > mid) ans += qurry(rson);
    return ans;
}
int C;
int qq(int l,int r,int o)
{
    if(l == r)
        return l;
    int mid = (l + r) >> 1;
    if(C > sum[o<<1])
    {
        C -= sum[o<<1];
        return qq(rson);
    }

    else
        return qq(lson);
}
int main()
{
    while(scanf("%d %d %d",&n,&m,&k) != EOF)
    {
        int tot;
        memset(sum,0,sizeof(sum));
        scanf("%d",&tot);
        int i,j;
        A = 0;
        update(0,n+1,1);
        A = n + 1;
        update(0,n+1,1);
        int ans = n / (k + 1);
        if(n % (k + 1) == k)
            ans++;
        int ok = 1;
        int last = -1;
        for(i = 1; i <= tot; i++)
        {
            int l,r,kk;
            scanf("%d",&kk);
            A = 0,B = kk;
            int ss = qurry(0,n+1,1);
            C = ss;
            l = qq(0,n+1,1);
            C = ss + 1;
            r = qq(0,n+1,1);
            int len = r - l - 1;
            int ans1 = len / (k + 1);
            if(len %(k + 1) == k)
                ans1++;
            ans -= ans1;
            len = kk - l - 1;
            ans1 = len / (k + 1);
            if(len %(k + 1) == k)
                ans1++;
            ans += ans1;
            len = r - kk - 1;
            ans1 = len / (k + 1);
            if(len %(k + 1) == k)
                ans1++;
            ans += ans1;
            if(ans < m && ok == 1)
            {
                last = i;
                ok = 0;
            }
            A = kk;
            update(0,n+1,1);
        }
        if(ok)
            printf("-1\n");
        else
            printf("%d\n",last);
    }
    return 0;
}
