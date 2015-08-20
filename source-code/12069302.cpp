//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;


const int k = 'z' - 'a' + 1;


int nextInt() {
    int x = 0;
    char c = getchar();

    while (!isdigit(c)) {
        c = getchar();
    }

    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }

    return x;
}


struct node;
node *newNode();


struct node {
    int lv, rv, sum, prom, len;
    node *left, *right;


    node() : left(NULL), right(NULL), sum(0), prom(0) {}


    void assign(int l, int r) {
        lv = l;
        rv = r;
        len = rv - lv + 1;

        if (l < r) {
            left = newNode();
            right = newNode();
            int m = (l + r) / 2;
            left->assign(l, m);
            right->assign(m + 1, r);
        }
    }


    inline void push() {
        if (!prom) {
            return;
        }

        if (prom == 1) {
            left->sum = left->len;
            right->sum = right->len;
        }

        if (prom == 2) {
            left->sum = right->sum = 0;
        }

        left->prom = right->prom = prom;
        prom = 0;
    }


    int getSum(int l, int r) {
        if (r < lv || rv < l || !sum) {
            return 0;
        }

        if (l <= lv && rv <= r) {
            return sum;
        }

        push();
        return left->getSum(l, r) + right->getSum(l, r);
    }


    void set(int l, int r) {
        if (r < lv || rv < l) {
            return;
        }

        if (l <= lv && rv <= r) {
            sum = len;
            prom = 1;
            return;
        }

        push();
        left->set(l, r);
        right->set(l, r);
        sum = left->sum + right->sum;
    }


    void erase(int l, int r) {
        if (r < lv || rv < l) {
            return;
        }

        if (l <= lv && rv <= r) {
            sum = 0;
            prom = 2;
            return;
        }

        push();
        left->erase(l, r);
        right->erase(l, r);
        sum = left->sum + right->sum;
    }
};


node *newNode() {
    static int bufSize = 1e7;
    static node buf[(int) 1e7];
    assert(bufSize);
    return &buf[--bufSize];
}


main() {
#ifndef ONLINE_JUDGE
    freopen("1.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n = nextInt(), m = nextInt();
    scanf("\n");
    string s;
    getline(cin, s);
    vector<node*> letterRoot;

    for (int i = 0; i < k; i++) {
        letterRoot.push_back(newNode());
        letterRoot.back()->assign(0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        s[i] -= 'a';
        letterRoot[s[i]]->set(i, i);
    }

    ///********************************

    while (m--) {
        int l = nextInt(), r = nextInt();
        l--; r--;
        static vector<int> cnt(k), order(k);

        for (int i = 0; i < k; i++) {
            cnt[i] = letterRoot[i]->getSum(l, r);
            letterRoot[i]->erase(l, r);
        }

        for (int i = 0; i < k; i++) {
            order[i] = i;
        }

        if (!nextInt()) {
            reverse(order.begin(), order.end());
        }

        for (int sym : order) {
            letterRoot[sym]->set(l, l + cnt[sym] - 1);
            l += cnt[sym];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            if (letterRoot[j]->getSum(i, i)) {
                printf("%c", 'a' + j);
            }
}
