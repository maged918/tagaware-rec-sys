//Language: GNU C++11


/*
10 5
abacdabcda
7 10 0
5 8 1
1 4 0
3 6 0
7 10 1

10 1
agjucbvdfk
1 10 1

*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using vi = vector<int>;
using i64 = long long;

// Max Value Segment Tree + Range Update with Lazy Propagation

struct Node {
  int s, e;       // Interval covered by this node
  int son[2];     // Children of this node
  int val, lazy;  // Node info + Data to propagate
};

struct SegmentTree {
  vector<Node> T;

  SegmentTree(const string& s, char ch) {
    const int N = s.size();
    
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    n.val = 0, n.lazy = inf;

    T.reserve(4 * N);
    T.push_back(n);
    init(0, s, ch);
  }

  void init(int u, const string& s, char ch) {
    Node &n = T[u];
    if (n.e - n.s == 1)
    {
      n.val = (s[n.s] == ch ? 1 : 0);
      return;
    }
    
    int mid = (n.s + n.e) / 2;
    for (int i = 0; i < 2; i++) {
      Node c(n);
      if (i == 0)
        c.e = mid;
      else {
        c.son[0] = -1;
        c.s = mid;
      }
      n.son[i] = T.size();
      T.push_back(c);
      init(n.son[i], s, ch);
    }
    
    n.val = T[n.son[0]].val + T[n.son[1]].val;
  }

  void update(int u, int le, int ri, int val) {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri) return;

    if (n.s == le && n.e == ri) {
      n.lazy = val;
      n.val = (n.e - n.s) * val;
      return;
    }
    
    push_lazy(u);
    if (le < T[n.son[0]].e) {
      update(n.son[0], le, min(T[n.son[0]].e, ri), val);
      update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    } else {
      update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    }
    n.val = T[n.son[0]].val + T[n.son[1]].val;
  }

  void push_lazy(int u) {
    Node &n = T[u];
    if (n.lazy == inf) return;

    for (int i = 0; i < 2; i++) {
      if (n.son[i] != -1) {
        Node &son = T[n.son[i]];
        son.lazy = n.lazy;
        son.val = (son.e - son.s) * n.lazy;
      }
    }
    n.lazy = inf;
  }

  int query(int u, int le, int ri) {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri) return 0;

    if (n.s == le && n.e == ri) return n.val;

    push_lazy(u);
    int res = query(n.son[0], le, min(T[n.son[0]].e, ri));
    res += query(n.son[1], max(T[n.son[1]].s, le), ri);
    return res;
  }
};

int main() {
  constexpr int kAlphasize = 'z' - 'a' + 1;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, q, freq[kAlphasize];
  while (cin >> n >> q) {
    string s;
    cin >> s;
    
    vector<SegmentTree> stvec;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      stvec.emplace_back(s, ch);
    }
    
    for (int i = 0; i < q; i++) {
      //cerr << "Query #" << (i + 1) << endl;
      
      int a, b, k;
      cin >> a >> b >> k;
      a -= 1, b -= 1;
      
      int sum = 0;
      //cerr << "\tBefore\n\t";
      for (int j = 0; j < kAlphasize; ++j) {
        freq[j] = stvec[j].query(0, a, b + 1);
        //cerr << freq[j] << " ";
        stvec[j].update(0, a, b + 1, 0);
        sum += freq[j];
      }
      //cerr << endl;
      assert(sum == (b - a + 1));
      
      /*
      cerr << "\tMiddle\n\t";
      for (int i = 0; i < kAlphasize; i++) {
        cerr << stvec[i].query(0, a, b + 1) << " ";
      }
      cerr << endl;
      */
      
      if (k == 1) {
        int next = a;
        for (int c = 0; c < kAlphasize; ++c) {
          int next_end = freq[c] + next;
          if (next < next_end) {
            //cerr << "Letter: " << char(c + 'a') << ", " << next << ", " << next_end << endl;
            stvec[c].update(0, next, next_end, 1);
            next = next_end;
          }
        }
        assert(next == b + 1);
      } else {
        int next = a;
        for (int c = kAlphasize - 1; c >= 0; --c) {
          int next_end = freq[c] + next;
          if (next < next_end) {
            //cerr << "Letter: " << char(c + 'a') << ",  " << next << ", " << next_end << endl;
            stvec[c].update(0, next, next_end, 1);
            next = next_end;
          }
        }
        assert(next == b + 1);
      }
      
      /*
      cerr << "\tAfter\n\t";
      for (int i = 0; i < kAlphasize; i++) {
        cerr << stvec[i].query(0, a, b + 1) << " ";
      }
      cerr << endl;
      */
    }
    
    string result(n, '*');
    for (int i = 0; i < n; i++) {
      // Find the letter in this position
      for (int c = 0; c < kAlphasize; c++) {
        if (stvec[c].query(0, i, i + 1) > 0) {
          result[i] = c + 'a';
          break;
        }
      }
    }
    cout << result << '\n';
  }
  
  return 0;
}