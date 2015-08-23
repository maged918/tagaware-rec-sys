//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 100005;
const int M = 1000005;
int a[N], b[M], c[M], d[N];
int main()
{
    int n, l, r, k, t;
    scanf("%d", &n);
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(b[a[i]] == 0)
            b[a[i]] = i;
        c[a[i]]++;
        d[i] = c[a[i]];
    }
    k = 0;
    for(int i = 1; i <= n; i++)
        if(d[i] > k)
        {
            k = d[i];
            t = a[i];
            r = i;
            l = b[a[i]];
        }
        else if(d[i]==k && a[i]!=t)
        {
            int tr = i;
            int tl = b[a[i]];
            if(tr-tl < r-l)
            {
                t = a[i];
                l = tl;
                r = tr;
            }
        }
    printf("%d %d\n", l, r);
    return 0;
}
