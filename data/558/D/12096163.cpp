//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

struct node{
    int data, pr, l, r;

    node () {};
    node (LL data) : data(data), pr(0), l(0), r(0) {};
};

LL h, q, MAXN, pos;
node t[15000000];
LL t_size;

void TBuild(LL x, LL l, LL r){
    MAXN = r; //![)
}

void TPush(LL v){
    if (t[v].l == 0) t[v].l = ++t_size;
    if (t[v].r == 0) t[v].r = ++t_size;

    t[t[v].l].data += t[v].pr; t[t[v].l].pr += t[v].pr;
    t[t[v].r].data += t[v].pr; t[t[v].r].pr += t[v].pr;

    t[v].pr = 0;
}

void TInc(int v, LL tl, LL tr, LL l, LL r){
    if (l > r) return;
    if (l == tl && r == tr){
        ++t[v].data; ++t[v].pr;
        return;
    }

    TPush(v);
    LL tm = (tl + tr) / 2;
    TInc(t[v].l, tl, tm, l, min(r, tm));
    TInc(t[v].r, tm + 1, tr, max(l, tm + 1), r);
}

LL TGetAns(int v, LL tl, LL tr, LL q){
    if (!(t[v].l || t[v].r)){
        if (t[v].data == q) {
            pos = tl;
            return tr - tl + 1;
        }
        return 0;
    }

    LL ans = 0;
    LL tm = (tl + tr) / 2;
    if (t[v].l) ans += TGetAns(t[v].l, tl, tm, q - t[v].pr);
    if (t[v].r) ans += TGetAns(t[v].r, tm + 1, tr, q - t[v].pr);

    return ans;
}

int main(){
    scanf("%I64d %I64d", &h, &q); //cin >> h >> q;
    TBuild(0, 0, (1LL << (h - 1)) - 1);

    for (int i = 0; i < q; ++i) {
        LL level, l, r, ans;
        scanf("%I64d %I64d %I64d %I64d", &level, &l, &r, &ans); //cin >> level >> l >> r >> ans;
        LL ll = l * (1LL << (h - level)) - (1LL << (h - 1)), rr = (r + 1) * (1LL << (h - level)) - (1LL << (h - 1)) - 1;

        if (ans == 1){
            TInc(0, 0, MAXN, ll, rr);
        } else {
            TInc(0, 0, MAXN, 0, ll - 1);
            TInc(0, 0, MAXN, rr + 1, MAXN);
        }
    }

    LL ans = TGetAns(0, 0, MAXN, q);

    if (ans == 0) printf("Game cheated!");
    else if (ans == 1) printf("%I64d", pos + (1LL << (h - 1)));
    else printf("Data not sufficient!");

    return 0;
}
