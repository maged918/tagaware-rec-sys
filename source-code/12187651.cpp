//Language: GNU C++11


// 2015-07-22
#include <bits/stdc++.h>
#include <unordered_map>
#include <array>
#include <forward_list>
#include <unordered_set>
using namespace std;


#ifndef LOCAL
//#define LOCAL
#endif

#define SET_BIT(mask, index) (mask |= (1 << index))
#define TEST_BIT(mask, index) (mask & (1 << index))
#define CLEAR_BIT(mask, index) (mask &= ~(1 << index))
#define TOGGLE_BIT(mask, index) (mask ^= (1 << index))
const int INF = 1000000000;
const double EPS = 1.0e-11;
const int NO_VALUE = -1;
using ii = pair < int, int > ;
using ll = long long;
struct sc { template<class T> inline static T next() { T n; cin >> n; return n; } };

int r[4], c[4];
    
bool fits() {
    return ((r[2] <= r[1] && r[3] <= r[1] && c[2] <= c[1] && c[3] <= c[1]) && (r[2] + r[3] <= r[1] || c[2] + c[3] <= c[1]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w+", stdout);
#endif

    for (int i = 1; i <= 3; i++) {
        c[i] = sc::next<int>();
        r[i] = sc::next<int>();
    }
    
    
    bool answer = false;
    answer |= fits();
    
    swap(r[2], c[2]);
    answer |= fits();
    
    swap(r[3], c[3]);
    answer |= fits();
    
    swap(r[2], c[2]);
    answer |= fits();

    
    cout << (answer ? "YES" : "NO") << "\n";
    


    return 0;
}
