//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define eps 0.00005

int main() {
    int T, S, q;
    cin >> T >> S >> q;
    int time = 0;
    int played = S;
    int a = 1;
    while(1) {
        if(played >= T) {
            cout << a << '\n';
            return 0;
        }
        if(time >= played) {
            time = 0;
            a++;
        }
        time += q;
        played += q - 1;
    }
}