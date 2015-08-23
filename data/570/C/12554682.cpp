//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 300000 + 10

int n, m;
char s[N];

int doit()
{
    int res = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '.') cnt++;
        else
        {
            if(cnt > 1) res += cnt - 1;
            cnt = 0;
        }
    }
    if(cnt > 1)
    res += cnt - 1;
    return res;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        scanf("%s", s + 1);
        char c;
        int t;
        int ans = doit();
        for(int i = 0; i < m; i++)
        {
            scanf("%d %c", &t, &c);
            if(s[t] != '.' && c == '.')
            {
                s[t] = c;
                if(t - 1 > 0 && s[t - 1] == '.') ans += 1;
                if(t + 1 <= n && s[t + 1] == '.') ans += 1;
            }
            else if(s[t] == '.' && c != '.')
            {
                s[t] = c;
                if(t - 1 > 0 && s[t - 1] == '.') ans -= 1;
                if(t + 1 <= n && s[t + 1] == '.') ans -= 1;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

/*

10 3
.b..bz....
1 h
3 c
9 f

4 4
.cc.
2 .
3 .
2 a
1 a


2 7
ab
1 w
2 w
1 c
2 .
2 .
1 .
2 b

*/
