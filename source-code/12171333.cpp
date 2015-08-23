//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <deque>
#include <map>
using namespace std;
int main(){
    //freopen ("combo.in", "r", stdin);freopen ("combo.out", "w", stdout);
    //freopen ("input.txt", "r", stdin);freopen ("output.txt", "w", stdout);
    int a, b, x, y, k, l;
    cin >> a >> b >> x >> y >> k >> l;
    if(x + k <= b && max(y, l) <= a) cout << "YES" << endl;
    else if(x + k <= a && max(y, l) <= b) cout << "YES" << endl;
    else if(y + l <= b && max(x, k) <= a) cout << "YES" << endl;
    else if(y + l <= a && max(x, k) <= b) cout << "YES" << endl;
    else if(y + k <= a && max(x, l) <= b) cout << "YES" << endl;
    else if(y + k <= b && max(x, l) <= a) cout << "YES" << endl;
    else if(x + l <= b && max(y, k) <= a) cout << "YES" << endl;
    else if(x + l <= a && max(y, k) <= b) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

