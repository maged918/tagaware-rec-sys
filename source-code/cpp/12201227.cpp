//Language: GNU C++11


#include <cstdio>
#include <vector>
#include <iostream>
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a.size())
#define fo(i, a, b) for(__typeof(a) i(a), _b(b); i<_b; ++i)
#define fod(i, a, b) for(__typeof(a) i((a)-1), _b(b); i>=_b; --i)
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> ii;

int x, y, a[2], b[2];
int main(void) {
    cin >> x >> y;
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    fo(i, 0, 2) fo(j, 0, 2) {
        if(a[i]+b[j] <= x && max(a[i^1], b[j^1]) <= y) return cout << "YES", 0;
        if(max(a[i], b[j]) <= x && a[i^1] + b[j^1] <= y ) return cout << "YES", 0;
        swap(x, y);
        if(a[i]+b[j] <= x && max(a[i^1], b[j^1]) <= y) return cout << "YES", 0;
        if(max(a[i], b[j]) <= x && a[i^1] + b[j^1] <= y ) return cout << "YES", 0;
        swap(x, y);
    }
    cout << "NO";
    return 0;
}
