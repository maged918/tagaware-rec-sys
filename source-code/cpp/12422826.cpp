//Language: GNU C++11


#include <iostream>
using namespace std;
const int MAX = 100;
long long dp[MAX][MAX];
int a[MAX], b[MAX];
string s[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i] >> s[i] >> b[i];
        a[i]--;
        b[i]--;
        if (a[i] > b[i])
        {
            swap(a[i], b[i]);
            if (s[i] == ">=")
                s[i] = "<=";
            else if (s[i] == "<=")
                s[i] = ">=";
            else if (s[i] == "<")
                s[i] = ">";
            else if (s[i] == ">")
                s[i] = "<";
        }
    }
    for (int i = 0; i + 2 <= 2 * n; i++)
    {
        bool valid = true;
        for (int j = 0; j < k; j++)
        {
            int x, y;
            if (a[j] < i)
                x = 0;
            else if (a[j] < i + 2)
                x = 1;
            else
                x = 2;
            if (b[j] < i)
                y = 0;
            else if (b[j] < i + 2)
                y = 1;
            else
                y = 2;
            if (x == 0 && y == 1 && (s[j] == ">" || s[j] == "=" || s[j] == ">="))
                valid = false;
            if (x == 1 && y == 1 && (s[j] == "<" || s[j] == ">"))
                valid = false;
            if (x == 1 && y == 2 && (s[j] == "<" || s[j] == "=" || s[j] == "<="))
                valid = false;
        }
        if (valid)
            dp[i][i + 2] = 1;
    }
    for (int len = 2; len < 2 * n; len += 2)
        for (int l = 0; l < 2 * n; l++)
        {
            int r = l + len;
            if (r > 2 * n)
                continue;
            if (l >= 2)
            {
                bool valid = true;
                for (int i = 0; i < k; i++)
                {
                    int x, y;
                    if (a[i] < l - 2)
                        x = 0;
                    else if (a[i] < l)
                        x = 1;
                    else if (a[i] < r)
                        x = 2;
                    else
                        x = 3;
                    if (b[i] < l - 2)
                        y = 0;
                    else if (b[i] < l)
                        y = 1;
                    else if (b[i] < r)
                        y = 2;
                    else
                        y = 3;
                    if (x == 0 && y == 1 && (s[i] == ">" || s[i] == "=" || s[i] == ">="))
                        valid = false;
                    if (x == 1 && y == 1 && (s[i] == "<" || s[i] == ">"))
                        valid = false;
                    if (x == 1 && y == 3 && (s[i] == "<" || s[i] == "=" || s[i] == "<="))
                        valid = false;
                }
                if (valid)
                    dp[l - 2][r] += dp[l][r];
            }
            if (r + 2 <= 2 * n)
            {
                bool valid = true;
                for (int i = 0; i < k; i++)
                {
                    int x, y;
                    if (a[i] < l)
                        x = 0;
                    else if (a[i] < r)
                        x = 1;
                    else if (a[i] < r + 2)
                        x = 2;
                    else
                        x = 3;
                    if (b[i] < l)
                        y = 0;
                    else if (b[i] < r)
                        y = 1;
                    else if (b[i] < r + 2)
                        y = 2;
                    else
                        y = 3;
                    if (x == 0 && y == 2 && (s[i] == ">" || s[i] == "=" || s[i] == ">="))
                        valid = false;
                    if (x == 2 && y == 2 && (s[i] == "<" || s[i] == ">"))
                        valid = false;
                    if (x == 2 && y == 3 && (s[i] == "<" || s[i] == "=" || s[i] == "<="))
                        valid = false;
                }
                if (valid)
                    dp[l][r + 2] += dp[l][r];
            }
            if (l > 0 && r + 1 <= 2 * n)
            {
                bool valid = true;
                for (int i = 0; i < k; i++)
                {
                    int x, y;
                    if (a[i] < l - 1)
                        x = 0;
                    else if (a[i] < l)
                        x = 1;
                    else if (a[i] < r)
                        x = 2;
                    else if (a[i] < r + 1)
                        x = 3;
                    else
                        x = 4;
                    if (b[i] < l - 1)
                        y = 0;
                    else if (b[i] < l)
                        y = 1;
                    else if (b[i] < r)
                        y = 2;
                    else if (b[i] < r + 1)
                        y = 3;
                    else
                        y = 4;
                    if (x == 0 && (y == 1 || y == 3) && (s[i] == ">" || s[i] == "=" || s[i] == ">="))
                        valid = false;
                    if (x == 1 && y == 3 && (s[i] == "<" || s[i] == ">"))
                        valid = false;
                    if ((x == 1 || x == 3) && y == 4 && (s[i] == "<" || s[i] == "=" || s[i] == "<="))
                        valid = false;
                }
                if (valid)
                    dp[l - 1][r + 1] += dp[l][r];
            }
        }
    cout << dp[0][2 * n] << endl;
    return 0;
}