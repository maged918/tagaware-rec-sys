//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 200001;
char a[MAX_N];
char b[MAX_N];

bool div(int ab, int ae, int bb, int be)
{
    if ((ae-ab)%2 == 1 || (be-bb)%2 == 1) {
        for (int i = 0; i < ae-ab; ++i) {
            if (a[ab+i] != b[bb+i]) return false;
        }
        return true;
    }
    return (div(ab, (ab+ae)/2, bb, (bb+be)/2) && div((ab+ae)/2, ae, (bb+be)/2, be) ||
            div(ab, (ab+ae)/2, (bb+be)/2, be) && div((ab+ae)/2, ae, bb, (bb+be)/2) );
}

int main()
{
    gets(a);
    gets(b);

    if (strlen(a) != strlen(b) || !div(0, strlen(a), 0, strlen(b))) printf("NO\n");
    else printf("YES\n");

    return 0;
}
