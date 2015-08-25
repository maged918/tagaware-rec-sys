//Language: GNU C++11


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

vector< pair<LL, int> > e;

int main() {
    int h, q;
    scanf("%d%d", &h, &q);

    int in = 0;

    for (int i = 0; i < q; i++) {
        LL l, r;
        int lev, ans;
        scanf("%d%I64d%I64d%d", &lev, &l, &r, &ans);

        for (int j = lev; j < h; j++) {
            l *= 2;
            r = 2 * r + 1;
        }

        if (ans) {
            e.pb(mp(l, 1));
            e.pb(mp(r + 1, -1));
            in++;
        }
        else {
            e.pb(mp(l, -1));
            e.pb(mp(r + 1, 1));
        }
    }

    LL leftmost = (LL(1) << (h - 1)), rightmost = (LL(1) << h) - 1; 
    e.pb(mp(rightmost + 1, 0));
    sort(e.begin(), e.end());


    int balance = 0;
    LL start = -1, finish = -1;

    if (balance == in && leftmost < e[0].first) {
        start = leftmost;
        finish = e[0].first;
    }

    for (int i = 0; i < sz(e) - 1; i++) {               
        auto x = e[i];
        balance += x.second;
        if (balance == in) {
            if (start != -1) {
                finish++;
            }
            else {
                start = x.first;
                finish = e[i + 1].first;
            }
        }
    }

    if (start != -1) {
        if (start + 1 == finish) {
            cout << start << endl;
        }       
        else {
            cout << "Data not sufficient!" << endl;
        }
    }
    else {
        cout << "Game cheated!" << endl;
    }

    return 0;
}
