//Language: GNU C++11


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define forn(i, s, n) for (int i = s; i < n; i++)

using namespace std;

long long T, q, s;

int main() {
    cin >> T >> s >> q;
    
    int res = 1;
    
    s *= q;
    
    while (T > s) {
        s *= q;
        res++;
    }
    
    cout << res << endl;
    return 0;
}