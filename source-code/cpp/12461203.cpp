//Language: GNU C++11


#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define mp make_pair

vector <int> v;
map <int, int> m;
int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int i, j, n, k = 1, a;
    cin >> n;
    v.resize(n);
    for (i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] <= n ) m[v[i]] = 1;
    }
    for (i = 0; i < n; i++) {
        a = v[i];
        if (m[a] == 1) {
            cout << a << " ";
            m[a] = 2;
        } else {
            while (m[k] != 0) k++;
            cout << k << " ";
            m[k] = 1;
        }
    }
    return 0;
}