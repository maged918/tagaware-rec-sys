//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
struct pt{
    int val;
    char left;
    char right;
    int vall;
    int valr;
    int len;
    int col;
    pt(int val = 0, char left = 'a', char right = 'a', int vall = 0, int valr = 0, int len = 0, int col = 0) : val(val), left(left), right(right), vall(vall), valr(valr), len(len), col(col) {}
};
char s[300013];
struct Do{
    int n;
    vector <pt> t;
    Do(int n = 0) : n(n) { t.resize( n * 4 + 4); }
    pt comb(pt a, pt b) {
        if (a.right != '.' || b.left != '.') {
            return pt(a.val + b.val, a.left, b.right, a.vall, b.valr, a.len + b.len, a.col + b.col);
        }
        pt ans;
        ans.len = (a.len + b.len);
        if (a.valr > 1 && b.vall > 1) {
            ans.col = (a.col + b.col - 1);
            ans.val = (a.val + b.val);
        }
        else{
            if (a.valr == 1 && b.vall == 1) {
                ans.col = (a.col + b.col + 1);
                ans.val = (a.val + b.val + 2);
            }
            else{
                ans.col = a.col + b.col;
                ans.val = a.val + b.val + 1;
            }
        }
        ans.left = a.left;
        ans.right = b.right;
        if (a.len == a.vall) {
            ans.vall = a.len + b.vall;
        }
        if (b.len == b.valr) {
            ans.valr = b.len + a.valr;
        }
        return ans;
    }
    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = pt(0, s[l], s[l], (s[l] == '.') ? 1 : 0, (s[r] == '.') ? 1 : 0, 1, 0);
        }
        else{
            build(2 * v, l, (l + r) >> 1);
            build(2 * v + 1, ((l + r) >> 1) + 1, r);
            t[v] = comb(t[2 * v], t[2 * v + 1]);
        }
    }
    void build() { build(1, 0, n - 1); }
    void upd(int v, int l, int r, int pos, char val){
        if (l == r) {
            t[v] = pt(0, val, val, (val == '.') ? 1 : 0, (val == '.') ? 1 : 0,1 , 0);
        }
        else{
            if (pos <= ((l + r) >> 1)) {
                upd(2 * v, l, (l + r) >> 1, pos, val);
            }
            else{
                upd(2 * v + 1, ((l + r) >> 1) + 1, r, pos, val);
            }
            t[v] = comb(t[2 * v], t[2 * v + 1]);
        }
    }
    void upd(int pos, int val) { upd(1, 0, n - 1, pos, val); }
    pt get(int v, int tl, int tr, int l, int r){
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) return t[v];
        return comb(get(v * 2, tl, (tl + tr) >> 1, l, min(r, (tl + tr) >> 1)), get(v * 2 + 1, ((tl + tr) >> 1) + 1, tr, max(l, ((tl + tr) >> 1) + 1), r));
    }
    pt get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

int main() {
    int n, m; cin >> n >> m;
    Do tree(n);
    gets(s);
    gets(s);
    tree.build();
    for (int i = 1; i <= m; i++) {
        int t;
        char p; cin >> t >> p;
        tree.upd(t - 1, p);
        pt ans = tree.get(0, n - 1);
        cout << ans.val - ans.col << endl;
    }
}