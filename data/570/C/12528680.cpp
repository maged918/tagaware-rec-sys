//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

char str[300001];
int main()
{
    int n, q;
    cin >> n >> q;
    scanf("%s", str);
    int res = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '.'&&str[i + 1] == '.') res++;
    }

    char change[3]; int pos;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%s", &pos,change);
        if (str[pos-1] == '.'&&change[0]!='.')
        {
            if (pos == 1)
            {
                if (n >= 2 && str[1] == '.') res--;
            }
            else if (pos == len&&str[len - 2] == '.')res--;
            else
            {
                if (len>=3&&str[pos] == '.'&&str[pos - 2] == '.')
                {
                    res -= 2;
                }
                else if (len >= 3 && str[pos] == '.'&&str[pos - 2] != '.') res--;
                else if (len >= 3 && str[pos] != '.'&&str[pos - 2] == '.') res--;
            }
            str[pos - 1] = change[0];
        }
        
        else if (str[pos - 1] != '.'&&change[0] == '.')
        {
            if (pos == 1)
            {
                if (n >= 2 && str[1] == '.') res++;
            }
            else if (pos == len&&str[len - 2] == '.') res++;
            else
            {
                if (len >= 3 && str[pos] == '.'&&str[pos - 2] == '.')
                    res += 2;
                else if (len >= 3 && str[pos] == '.'&&str[pos - 2] != '.') res++;
                else if (len >= 3 && str[pos] != '.'&&str[pos - 2] == '.') res++;
            }
            str[pos - 1] = change[0];
        }
        printf("%d\n", res);
    }

}