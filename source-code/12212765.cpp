//Language: GNU C++11


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define _1 first
#define _2 second


using namespace std;


typedef long long LL;


int h, q;


vector<pair<LL, LL> > p;


int main() {

    scanf("%d%d", &h, &q);

    LL _r = 2;
    LL _l = 1;
    for (int i = 1; i < h; ++i) {
        _r <<= 1;
        _l <<= 1;
    }
    p.push_back({_r, 0});
    p.push_back({_l, 0});


    for (int i = 0; i < q; ++i) {
        LL level, e, l, r;
        scanf("%I64d%I64d%I64d%I64d", &level, &l, &r, &e);
        ++r;
        for ( ; level < h; ++level) {
            l <<= 1;
            r <<= 1;
        }
        if (e) {
            p.push_back({_l, 1});
            p.push_back({l, -1});
            p.push_back({r, 1});
        }
        else {
            p.push_back({l, 1});
            p.push_back({r, -1});
        }
    }

    sort(p.begin(), p.end());

    LL length = 0, sum = 0, minX = 0;

    for (auto l = p.begin(), r = p.begin() + 1; r != p.end(); ++l, ++r)  {
        sum += l->_2;
        if (l->_1 != r->_1 && sum == 0) {
            length += r->_1 - l->_1;
            minX = l->_1;
        }
    }
    
    if (length == 0)
        puts("Game cheated!");
    else if (length == 1)
        printf("%I64d\n", minX);
    else
        puts("Data not sufficient!");

    return 0;
 }
