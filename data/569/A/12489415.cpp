//Language: GNU C++


#include <cstdio>

using namespace std;

int main ()
{
    int t, s, q;
    scanf ("%d %d %d", &t, &s, &q);

    int nr = 0;
    while (s < t)
    {
        s *= q;
        ++nr;
    }

    printf ("%d\n", nr);

    return 0;
}
