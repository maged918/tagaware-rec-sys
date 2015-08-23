//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long int lli;
#define INF 1000000000

#define PMAX 3000000
bool not_prime[PMAX];
lli pr[PMAX];
lli n_primes;
lli counter[PMAX];

lli palindromes[PMAX];

lli v[20];
bool pal (lli n) {
    if (n == 12)
    {}
    lli cnt = 0;
    while (n > 0) {
        v[cnt] = n % 10;
        n /= 10;
        cnt++;
    }
    for (lli i = 0; i < cnt; i++)
        if (v[i] != v[cnt-i-1])
            return false;
    return true;
}

lli p, q;
lli ans;

int main() {
    
    cin >> p >> q;
    
    lli pal_count = 1;
    palindromes[1] = 1;
    lli c = 2, cnt = 0;
    bool found = false;
    while ( c <= PMAX ) {
        if (!(palindromes[c-1] * p >= n_primes * q)) {
            if (c-2 > ans && !found) {
                ans = c-2;
                found = true;
            }
        }
        else found = false;
        
        if (pal(c)) {
            pal_count++;
        }
        palindromes[c] = pal_count;
        
        if (not_prime[c]) {
            counter[c] = n_primes;
            c++; continue;
        }
        pr[cnt] = (c);
        cnt++;
        n_primes++;
        for (lli i = 2*c; i <= PMAX; i+=c)
            not_prime[i] = true;
        
        c++;
    }
    if (ans != 0)
        cout << ans << "\n";
    else
        cout << "Palindromic tree is better than splay tree\n";
    
    return 0;
}