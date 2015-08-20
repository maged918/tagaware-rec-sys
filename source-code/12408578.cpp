//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35 * 2 + 10;
const int MAXK = 100 + 10;

int n, k;
struct Condition {
    int x, y;
    enum Relation {
        EQ, LT, GT, LE, GE
    } r;
    void input() {
        char s[3];
        scanf("%d%s%d", &x, s, &y);
        if (strlen(s) == 1) {
            switch (s[0]) {
            case '=': r = EQ; break;
            case '<': r = LT; break;
            case '>': r = GT; break;
            }
        } else {
            r = s[0] == '<' ? LE : GE;
        }
    }
    void reverse() {
        swap(x, y);
        switch (r) {
        case LT: r = GT; break;
        case GT: r = LT; break;
        case LE: r = GE; break;
        case GE: r = LE; break;
        default: break;
        }
    }
} cond[MAXK];
bool relate[MAXN][MAXK];

long long dp[MAXN][MAXN];

bool checkSingle(int l, int r, int a, int i) {
    if (cond[i].y == a) {
        cond[i].reverse();
    }
    switch (cond[i].r) {
    case Condition::EQ:
        return false;
    case Condition::LT:
    case Condition::LE:
        return l <= cond[i].y && cond[i].y <= r;
    case Condition::GT:
    case Condition::GE:
        return cond[i].y < l || cond[i].y > r;
    }
    return false;
}

bool check(int l, int r, int a, int b) {
    for (int i = 0; i < k; ++i) {
        if (relate[a][i] && relate[b][i]) {
            if (cond[i].r == Condition::LT || cond[i].r == Condition::GT) {
                return false;
            }
        } else if (relate[a][i]) {
            if (!checkSingle(l, r, a, i)) {
                return false;
            }
        } else if (relate[b][i]) {
            if (!checkSingle(l, r, b, i)) {
                return false;
            }
        }
    }
    return true;
}

long long calc(int l, int r) {
    if (dp[l][r] == -1) {
        if (l + 1 == r) {
            dp[l][r] = check(l, r, l, r);
        } else {
            dp[l][r] = 0;
            if (check(l, r, l, l + 1)) {
                dp[l][r] += calc(l + 2, r);
            }
            if (check(l, r, l, r)) {
                dp[l][r] += calc(l + 1, r - 1);
            }
            if (check(l, r, r - 1, r)) {
                dp[l][r] += calc(l, r - 2);
            }
        }
//        cout << l << " " << r << " " << dp[l][r] << endl;
    }
    return dp[l][r];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
        cond[i].input();
        if (cond[i].x == cond[i].y) {
            if (cond[i].r == Condition::LT || cond[i].r == Condition::GT) {
                puts("0");
                return 0;
            }
        } else {
            relate[cond[i].x][i] = true;
            relate[cond[i].y][i] = true;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << calc(1, n * 2) << endl;
    return 0;
}
