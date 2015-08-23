//Language: GNU C++


#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    int n, m, cs, tmp;
    int a[101];
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u;
        cs = 1; tmp = 0;
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &u);
            if (u > tmp) cs = j, tmp = u;
        }
        a[cs]++;
    }
    cs = 1;
    tmp = 0;
    for(int i = 1; i <= n; i++)
        if (a[i] > tmp)
        {
            tmp = a[i];
            cs = i;
        }
    printf("%d", cs);
}
