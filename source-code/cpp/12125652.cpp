//Language: GNU C++11


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(x, a, b) for(int x=(a); x<(b); x++)
#define RI(a) scanf("%d", &a)
#define RD(a) scanf("%lf", &a)
using namespace std;

struct Node{
    int l, r, cov, sum;
    Node *lchild, *rchild;
    Node(int _l, int _r, Node* _lc, Node* _rc) {
        lchild = _lc; rchild = _rc;
        l = _l, r = _r;
        cov = -1;
        sum = 0;
    }
} *root[26];

int n, m;
char str[100005];

Node* build(int L, int R) {
    if (L == R)
        return new Node(L, R, NULL, NULL);
    int M = (L+R)/2;
    return new Node(L, R, build(L, M), build(M+1, R));
}

void push(Node *node) {
    if (node->cov == -1) return;
    node->lchild->cov = node->rchild->cov = node->cov;
    if (node->cov) {
        node->lchild->sum = node->lchild->r - node->lchild->l + 1;
        node->rchild->sum = node->rchild->r - node->rchild->l + 1;
    }
    else
        node->lchild->sum = node->rchild->sum = 0;
    node->cov = -1;
    node->sum = 0;
}

void pull(Node *node) {
    node->sum = node->lchild->sum + node->rchild->sum;
}

void update(Node *node, int L, int R, int v) {
    if (L > R) return;
    if (R < node->l || node->r < L) return;
    if (L <= node->l && node->r <= R) {
        node->cov = v;
        if (v)
            node->sum = node->r - node->l + 1;
        else
            node->sum = 0;
        return;
    }
    push(node);
    update(node->lchild, L, R, v);
    update(node->rchild, L, R, v);
    pull(node);
}

int query(Node *node, int L, int R) {
    if (L > R) return 0;
    if (R < node->l || node->r < L) return 0;
    if (L <= node->l && node->r <= R) return node->sum;
    push(node);
    int a1 = query(node->lchild, L, R);
    int a2 = query(node->rchild, L, R);
    pull(node);
    return a1 + a2;
}

void print_string() {
    memset(str, 0, sizeof(str));
    for (int i=0; i<26; i++) {
        for (int j=1; j<=n; j++)
            if (query(root[i], j, j))
                str[j] = 'a'+i;
    }
    puts(str+1);
}

int main() {
    RI(n); RI(m);
    scanf(" %s", str+1);
    for (int i=0; i<26; i++)
        root[i] = build(1, n);
    for (int i=1; i<=n; i++)
        update(root[str[i]-'a'], i, i, 1);

    int l, r, k, cnt[26];
    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        for (int i=0; i<26; i++) {
            cnt[i] = query(root[i], l, r);
            update(root[i], l, r, 0);
        }
        int s = 0;
        if (k == 1)
            for (int i=0; i<26; i++) {
                update(root[i], l+s, l+s+cnt[i]-1, 1);
                s += cnt[i];
            }
        else
            for (int i=25; i>=0; i--) {
                update(root[i], l+s, l+s+cnt[i]-1, 1);
                s += cnt[i];
            }
        // print_string();
    }
    print_string();
    /*
    char ch;
    int a, b;
    while(scanf(" %c %d %d", &ch, &a, &b)) {
        printf("%d\n", query(root[ch-'a'], a, b));
    }
    */
    return 0;
}
