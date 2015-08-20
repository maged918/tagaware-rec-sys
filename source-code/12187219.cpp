//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+10;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int tn, n, m, tcase = 0;

char a[2*MAX], b[2*MAX];

int dfs(int x1, int y1, int x2, int y2)
{
    for(int i = x1, j = x2; i<y1; i++, j++) 
        if(a[i] != b[j]) break;
        else if(i == y1-1) return 1;
    if((y1-x1)%2 != 0) return 0;
    if(dfs(x1, (x1+y1)/2, x2, (x2+y2)/2) && dfs((x1+y1)/2, y1, (x2+y2)/2, y2))
        return 1;
    else if(dfs(x1, (x1+y1)/2, (x2+y2)/2,y2) && dfs((x1+y1)/2, y1, x2, (x2+y2)/2))
        return 1;
    return 0;
}

int main()
{
#ifdef OFFLINE
    freopen("input.txt", "r", stdin);
#endif // OFFLINE

    while(~scanf("%s%s", a, b))
    {
        int len = strlen(a);
        if(dfs(0, len, 0, len)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}