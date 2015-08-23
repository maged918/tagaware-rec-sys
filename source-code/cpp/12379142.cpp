//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
using namespace std;
typedef long long int lli;
#define INF 200000000

int sz;
int len, nship;
int S[300000];
set<int> miss;

int ships_in_range (int a, int b) {
    b--;
    int res = (b-a) /(sz+1);
    if ((b-a) % (sz+1) == sz)
        res ++;
    return res;
}

int main() {
    
    cin >> len >> nship >> sz;
    int ops; cin >> ops;
    
    set<int> :: iterator it, it1, it2;
    int space = ships_in_range(0, len+1);
    S[0] = space;
    miss.insert(0); miss.insert(len+1);
    for (int o = 0; o < ops; o++) {
        int x; cin >> x;
        it = it1 = it2 = miss.insert(x).first;
        
        it1 --;
        ++it2;
        space -= S[*it1];
        S[*it1] = ships_in_range(*it1, *it);
        S[*it] = ships_in_range(*it, *it2);
        space += S[*it1] + S[*it];
        
        if (space < nship) {
            cout << o+1 << "\n";
            return 0;
        }
    }
    
    cout << "-1\n";
    
    return 0;
}