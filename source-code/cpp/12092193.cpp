//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> zeros, ones;

int main() {
    int h, q;
    scanf("%d%d", &h, &q);
    for (int i = 0; i < q; i++) {
        int id, ans;
        long long L, R;
        scanf("%d%I64d%I64d%d", &id, &L, &R, &ans);
        for (int j = id; j < h; j++) {
            L = L * 2;
            R = R * 2 + 1;
        }
        if (ans == 0) {
            zeros.push_back({L, R});
        } else {
            ones.push_back({L, R});
        }
    }   
    long long maxL = 1, maxR = 1;
    for (int i = 1; i < h; i++) {
        maxL *= 2;
        maxR = maxR * 2 + 1;
    }
    long long ansL = maxL, ansR = maxR;
    for (auto x : ones) {
        ansL = max(ansL, x.first);
        ansR = min(ansR, x.second);
    }
    sort(zeros.begin(), zeros.end());
    long long preL = maxL;
    long long sol = 0, solcnt = 0;
    int n = zeros.size();
    for (int i = 0; i < n; i++) {
        long long L = zeros[i].first, R = zeros[i].second;
        while (i < n && zeros[i].first <= R) {
            R = max(R, zeros[i].second);
            i++;
        }
        i--;
        long long preR = L - 1;
        preL = max(preL, ansL);
        preR = min(preR, ansR);
        if (preL <= preR) {
            if (preR - preL + 1 == 1) {
                sol = preL;
            }
            solcnt += preR - preL + 1;
        }
        preL = R + 1;
    }
    long long preR = maxR;
    preL = max(preL, ansL);
    preR = min(preR, ansR);
    if (preL <= preR) {
        if (preR - preL + 1 == 1) {
            sol = preL;
        }
        solcnt += preR - preL + 1;
    }
    if (solcnt == 0) {
        puts("Game cheated!");
    } else if (solcnt == 1) {
        printf("%I64d\n", sol);
    } else {
        puts("Data not sufficient!");
    }
    return 0;
}