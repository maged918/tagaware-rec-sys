//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100010, ALPHABET_SIZE = 26;

int N, Q;
char str[NMAX];

struct Tree {
    int index[ALPHABET_SIZE];
    char flag;
} T[4 * NMAX];

inline void MergeNodes(int node) {
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        T[node].index[i] = T[node * 2].index[i] + T[node * 2 + 1].index[i];
}

void BuildTree(int node, int left, int right) {
    T[node].flag = -1;
    if (left == right) {
        T[node].index[str[left] - 'a'] = 1;
        return;
    }

    if (left > right)
        return;

    int mid = (left + right) / 2;
    BuildTree(node * 2, left, mid);
    BuildTree(node * 2 + 1, mid + 1, right);

    MergeNodes(node);
}

inline void UnLazyNode(int node, int left, int right) {
    if (left == right || T[node].flag == -1) return;

    T[node * 2].flag = T[node * 2 + 1].flag = T[node].flag;
    memset(T[node * 2].index, 0, sizeof(T[node * 2].index));
    memset(T[node * 2 + 1].index, 0, sizeof(T[node * 2 + 1].index));

    int mid = (left + right) / 2;
    T[node * 2].index[int(T[node].flag)] = mid - left + 1;
    T[node * 2 + 1].index[int(T[node].flag)] = right - mid;

    T[node].flag = -1;
}

int QueryTree(int node, int left, int right, int qleft, int qright, int pos) {
    if (qleft <= left && qright >= right)
        return T[node].index[pos];

    if (left >= right)
        return 0;

    int mid = (left + right) / 2, ret = 0;
    UnLazyNode(node, left, right);
    if (qleft <= mid) ret += QueryTree(node * 2, left, mid, qleft, qright, pos);
    if (qright > mid) ret += QueryTree(node * 2 + 1, mid + 1, right, qleft, qright, pos);

    return ret;
}

void UpdateTree(int node, int left, int right, int qleft, int qright, char flag) {
    if (qleft <= left && qright >= right) {
        memset(T[node].index, 0, sizeof(T[node].index));
        T[node].flag = flag;
        T[node].index[int(flag)] = right - left + 1;
        return;
    }

    if (left >= right)
        return;

    int mid = (left + right) / 2;
    UnLazyNode(node, left, right);
    if (qleft <= mid) UpdateTree(node * 2, left, mid, qleft, qright, flag);
    if (qright > mid) UpdateTree(node * 2 + 1, mid + 1, right, qleft, qright, flag);

    MergeNodes(node);
}

void PrintTree(int node, int left, int right) {
    if (left == right) {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            if (T[node].index[i]) {
                cout << char(i + 'a');
                return;
            }
    }

    if (left > right)
        return;

    int mid = (left + right) / 2;
    UnLazyNode(node, left, right);
    PrintTree(node * 2, left, mid);
    PrintTree(node * 2 + 1, mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
//    ifstream cin("debug.in");

    int x, y, inc, i;
    int num[ALPHABET_SIZE];

    cin >> N >> Q >> (str + 1);

    BuildTree(1, 1, N);
    while (Q--) {
        cin >> x >> y >> inc;

        for (i = 0; i < ALPHABET_SIZE; ++i)
            num[i] = QueryTree(1, 1, N, x, y, i);

        if (inc) {
            int last = x;
            for (i = 0; i < ALPHABET_SIZE; ++i) {
                if (num[i] == 0) continue;
                UpdateTree(1, 1, N, last, last + num[i] - 1, i);
                last += num[i];
            }
        } else {
            int last = x;
            for (i = ALPHABET_SIZE - 1; i >= 0; --i) {
                if (num[i] == 0) continue;
                UpdateTree(1, 1, N, last, last + num[i] - 1, i);
                last += num[i];
            }
        }
    }

    PrintTree(1, 1, N);
    cout << '\n';
    return 0;
}
