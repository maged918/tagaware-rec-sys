//Language: GNU C++


#include <stdio.h>

using namespace std;

int n, k;
bool f = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k == 1) f = 1;
    }
    if (f) printf("-1\n");
    else printf("1\n");
}
