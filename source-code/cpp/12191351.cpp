//Language: GNU C++11


#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a1, b1, a2, b2, a3, b3;

bool ok(int x, int y)   {
    if ((x <= a1 && y <= b1) || (x <= b1 && y <= a1))   return true;
    else    return false;
}

int main(void)  {
    scanf ("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
    if (ok (a2+a3, max (b2, b3)) || ok (b2+b3, max (a2, a3)) ||
        ok (a2+b3, max (b2, a3)) || ok (b2+a3, max (a2, b3)))   {
        puts ("YES");
    }
    else    puts ("NO");

    return 0;
}
