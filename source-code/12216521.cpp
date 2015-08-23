//Language: GNU C++11


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int SZ = 200000;
char tmp[SZ];
char ans[SZ];
char ans2[SZ];


inline void combine(char *a, char *b, int sz) {
    bool eq = true;
    for (int i = 0; i < sz; i++) {
        if (a[i] < b[i]) return;
        if (a[i] > b[i]) {
            eq = false;
            break;
        }
    }
    if (eq) return;
    for (int i = 0; i < sz; i++) {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}
void doit(char *in, int N) {
    int qtd = 1;
    int N2 = N;
    while ((N2 & 1) == 0) {
        N2 >>= 1;
        qtd <<= 1;
    }
    char *tmp = in;
    for (int i = 0; i < qtd; i++) {
        // combine while right most digit is 1
        tmp += N2;
        int ii = i;
        int sz = N2;
        while ((ii & 1) == 1) {
            combine(tmp - 2*sz, tmp - sz, sz);
            sz <<= 1;
            ii >>= 1;
        }
    }
}

int main() {
    int N;
    scanf(" %s%n", ans, &N);
    doit(ans, N);
    
    scanf(" %s", ans2);
    doit(ans2, N);
    
    if (memcmp(ans, ans2, N) == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
