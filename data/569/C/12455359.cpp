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

const int MAX_N = 10000000;

int is_rub[MAX_N];
int is_prime[MAX_N];

int num_rub[MAX_N];
int num_prime[MAX_N];

int main() {
    forn (i, 2, MAX_N)
        is_prime[i] = 1;
    
    forn (i, 2, 5000) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_N; j += i)
                is_prime[j] = 0;
        }
    }
    
    forn (i, 1, 10) {
        is_rub[i] = 1;
        is_rub[10 * i + i] = 1;
        
        forn (j, 0, 10) {
            is_rub[i * 100 + j * 10 + i] = 1;
            is_rub[i * 1000 + j * 100 + j * 10 + i] = 1;
            
            forn (k, 0, 10) {
                is_rub[i * 10000  + j * 1000  + k * 100            + j * 10 + i] = 1;
                is_rub[i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i] = 1;
                
                forn (p, 0, 10)
                    is_rub[i * 1000000 + j * 100000 + k * 10000 + p * 1000 + k * 100 + j * 10 + i] = 1;

            }
        }
    }
    
    forn (i, 1, MAX_N) {
        num_rub[i] = num_rub[i - 1] + is_rub[i];
        num_prime[i] = num_prime[i - 1] + is_prime[i];
    }
    
    long long p, q;
    
    cin >> p >> q;
    
    int res = 1;
    
    forn (i, 1, MAX_N) {
        if (q * num_prime[i] <= p * num_rub[i]) {
            res = i;
        }
    }
    
    if (res == MAX_N - 1)
        cout << "Palindromic tree is better than splay tree\n";
    else
        cout << res << '\n';
    
    return 0;
}