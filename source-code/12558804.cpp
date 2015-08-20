//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


int c[3][3];
bool ok = false;

int a, b;

int main( )
{
    scanf("%d %d", &a, &b);
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++)
            scanf("%d", &c[i][j]);
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++)
        {
            int n = c[0][i] + c[1][j];
            int m = max(c[0][i ^ 1], c[1][j ^ 1]);
            if (n <= a && m <= b) ok = true;
            if (n <= b && m <= a) ok = true;
        }
    if (ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
