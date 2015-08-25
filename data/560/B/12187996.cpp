//Language: MS C++


#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <set>
#include <map>
#include <numeric>
#include <utility>
#include <list>
#include <queue>
using namespace std;
int main(){
    unsigned int a1, b1, a2, b2, a3, b3;
    cin >> a3 >> b3 >> a2 >> b2 >> a1 >> b1;
    if (a1 + a2 <= a3 && max(b1, b2) <= b3 || a1 + a2 <= b3 && max(b1, b2) <= a3 || b1 + b2 <= a3 && max(a1, a2) <= b3 || b1 + b2 <= b3 && max(a1, a2) <= a3
        || a1 + b2 <= a3 && max(b1, a2) <= b3 || a1 + b2 <= b3 && max(b1, a2) <= a3 || b1 + a2 <= a3 && max(a1, b2) <= b3 || b1 + a2 <= b3 && max(a1, b2) <= a3)
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}