//Language: GNU C++11


#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

const int N = 110100;
const int S = 30;

int n, q, nr[S], aint[4 * N][S], ca[4 * N];
char a[N];

void lup(int nod, int s1, int s2) {
    ca[2 * nod] = ca[2 * nod + 1] = ca[nod];
    memset(aint[2 * nod], 0, sizeof(aint[2 * nod]));
    memset(aint[2 * nod + 1], 0, sizeof(aint[2 * nod + 1]));

    aint[2 * nod][ca[nod]] = s1;
    aint[2 * nod + 1][ca[nod]] = s2;

    ca[nod] = 0;
}

void recalc(int nod) {

    for(int i = 1; i < S; ++i)
        aint[nod][i] = aint[2 * nod][i] + aint[2 * nod + 1][i];
}

void update(int nod, int pozx, int pozy, int poz1, int poz2, int cr) {
    if(pozx >= poz1 && poz2 >= pozy) {
        ca[nod] = cr;
        memset(aint[nod], 0, sizeof(aint[nod]));
        aint[nod][cr] = (pozy - pozx + 1);

        return;
    }

    int mid = (pozx + pozy) / 2;

    if(ca[nod])
        lup(nod, mid - pozx + 1, pozy - mid);

    if(mid >= poz1)
        update(2 * nod, pozx, mid, poz1, poz2, cr);
    if(mid < poz2)
        update(2 * nod + 1, mid + 1, pozy, poz1, poz2, cr);

    recalc(nod);
}

void calcnr(int nod, int pozx, int pozy, int poz1, int poz2) {
    if(pozx >= poz1 && pozy <= poz2) {
        for(int i = 1; i < S; ++i)
            nr[i] += aint[nod][i];

        return;
    }

    int mid = (pozx + pozy) / 2;

     if(ca[nod])
        lup(nod, mid - pozx + 1, pozy - mid);

    if(mid >= poz1)
        calcnr(2 * nod, pozx, mid, poz1, poz2);
    if(mid < poz2)
        calcnr(2 * nod + 1, mid + 1, pozy, poz1, poz2);

    recalc(nod);
}

void print(int nod, int pozx, int pozy) {
    if(ca[nod]) {
        for(int i = 0; i <= pozy - pozx; ++i)
            printf("%c", (char)(ca[nod] + 'a' - 1));
        return;
    }

    int mid = (pozx + pozy) / 2;

    print(2 * nod, pozx, mid);
    print(2 * nod + 1, mid + 1, pozy);
}

int main() {
    int i, j;
    //freopen("ttt", "r", stdin);

    cin >> n >> q;
    cin >> a;

    for(i = 0; i < n; ++i) {
        a[i] -= 'a';
        a[i]++;
        update(1, 1, n, i + 1, i + 1, a[i]);
    }

    for(int ii = 1; ii <= q; ++ii) {
        int l, r, op;
        scanf("%d%d%d", &l, &r, &op);

        memset(nr, 0, sizeof(nr));
        calcnr(1, 1, n, l, r);

        int pc = l;

        if(op == 0) {

            for(i = S - 1; i; --i) if(nr[i]) {
                update(1, 1, n, pc, pc + nr[i] - 1, i);
                pc += nr[i];
            }
        }
        else {

            for(i = 1; i < S; ++i) if(nr[i]) {
                update(1, 1, n, pc, pc + nr[i] - 1, i);
                pc += nr[i];
            }
        }

        //print(1, 1, n);
        //cout << "\n";
    }

    print(1, 1, n);

    return 0;
}
