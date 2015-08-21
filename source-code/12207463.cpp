//Language: GNU C++11


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

// start + (end - start) / 2;
/*
long long power(long long b, long long Pow){
if (b == 0) return 0;
else if (Pow == 1) return b;
else if (Pow % 2  == 0.0) return power(b*b, Pow / 2);
else return b*power(b*b, Pow / 2);
}*/
/*
int gcd(int a, int b){
if (b == 0)
return a;
return gcd(b, a % b);
}
*/
string s, t;
bool flag = 0;
bool can(int a, int b, int c, int d){
    string S, T;
    S = s.substr(a, b - a + 1);
    T = t.substr(c, d - c + 1);
    if (S == T)
        return true;
    if (S.size() && S.size() % 2 == 0 && S.size() == T.size()){
        int m1 = a + (b - a + 1) / 2;
        int m2 = c + (d - c + 1) / 2;
        return (can(a, m1 - 1, m2, d) && can(m1, b, c, m2 - 1)) || (can(a, m1 - 1, c, m2 - 1) && can(m1, b, m2, d));
    }
    else
        return false;
}
int main() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    cin >> s >> t;
    if (can(0, s.size() - 1, 0, t.size() - 1))  {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}