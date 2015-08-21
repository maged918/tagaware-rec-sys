//Language: GNU C++


#include <stdio.h>

int main()
{
    int t, s,  q;

    scanf("%d%d%d", &t, &s, &q);
    int times = 1;
    while((s = s * q) < t)
        times++;

    printf("%d", times);

    return 0;
}
