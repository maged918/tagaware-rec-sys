//Language: GNU C++11


/*
 * 567D. One-Dimensional Battle Ships.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

set<pair<int, int>> all;
set<pair<int, int>>::iterator it;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

    int n, k, a, m, p;
    scanf("%d%d%d%d", &n, &k, &a, &m);
    all.insert(make_pair(1, n));
    int maxi = 1 + (n - a) / (a + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p);
        it = --(all.upper_bound(make_pair(p, n)));
        pair<int, int> t = *it;
        all.erase(it);
        int len = t.second - t.first + 1, len1 = p - t.first, len2 = t.second
                - p;
        int before = 0, after = 0;
        if (len >= a)
            before += 1 + (len - a) / (a + 1);
        if (len1 >= a)
            after += 1 + (len1 - a) / (a + 1);
        if (len2 >= a)
            after += 1 + (len2 - a) / (a + 1);
        maxi += after - before;
        if (maxi < k) {
            printf("%d\n", ++i);
            return 0;
        }
        if (p > t.first)
            all.insert(make_pair(t.first, p - 1));
        if (p < t.second)
            all.insert(make_pair(p + 1, t.second));
    }
    printf("-1\n");
    return 0;
}
