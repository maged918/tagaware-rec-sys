//Language: GNU C++11


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    //freopen("out", "w", stdout);
    //freopen("in", "r", stdin);
    int t, s, q;
    scanf("%d%d%d", &t, &s, &q);
    int ans = 1;
    double tim = s;
    for(int i = 0; ; ++i) {
        double x = tim*q;
        if(x >= t) break;
        tim += x*(q-1)/q;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
