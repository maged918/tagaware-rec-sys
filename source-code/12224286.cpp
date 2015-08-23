//Language: GNU C++


/*
 * 558D. Guess Your Way Out! II - Set.cpp
 *
 *  Created on: Jul 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {


    int h, q;
    scanf("%d%d", &h, &q);
    set<pair<long long, long long> > ranges;
    set<pair<long long, long long> >::iterator it;
    ranges.insert(make_pair(1ll << (h - 1), (1ll << h) - 1));
    while (q--) {
        int hh, ans;
        long long l, r;
        scanf("%d%I64d%I64d%d", &hh, &l, &r, &ans);
        while (hh < h)
            l = l * 2, r = r * 2 + 1, hh++;
        if (ans) {
            while (ranges.size() && ranges.begin()->second < l)
                ranges.erase(ranges.begin());
            if (ranges.size() && ranges.begin()->first < l) {
                pair<long long, long long> temp = *ranges.begin();
                ranges.erase(ranges.begin());
                temp.first = l;
                ranges.insert(temp);
            }
            while (ranges.size() && (--ranges.end())->first > r)
                ranges.erase(--ranges.end());
            if (ranges.size() && (--ranges.end())->second > r) {
                pair<long long, long long> temp = *(--ranges.end());
                ranges.erase(--ranges.end());
                temp.second = r;
                ranges.insert(temp);
            }
        } else {
            while (it = ranges.lower_bound(make_pair(l, l)), it != ranges.end()
                    && it->second <= r)
                ranges.erase(it);
            if (it = ranges.lower_bound(make_pair(l, l)), it != ranges.end()
                    && it->first <= r) {
                pair<long long, long long> temp = *it;
                ranges.erase(it);
                temp.first = r + 1;
                ranges.insert(temp);
            }
            if (it = ranges.lower_bound(make_pair(l, l)), it != ranges.begin()
                    && (--it)->second >= l) {
                pair<long long, long long> temp = *(it);
                ranges.erase(it);
                ranges.insert(make_pair(temp.first, l - 1));
                if (temp.second > r)
                    ranges.insert(make_pair(r + 1, temp.second));
            }
        }
    }
    if (!ranges.size())
        printf("Game cheated!\n");
    else if (ranges.size() > 1
            || ranges.begin()->second - ranges.begin()->first)
        printf("Data not sufficient!\n");
    else
        printf("%I64d\n", ranges.begin()->first);
    return 0;
}
