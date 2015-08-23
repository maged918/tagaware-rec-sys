//Language: GNU C++11


/* ***********************************************
    Author        : Napoleon
    Mail          : tyfdream@163.com
    Created Time  : 2015-07-22 21:56:34
    Problem       : cf2.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 
int a[10], b[10]; 

int test(int aa, int bb, int cc) {
    int x[10], y[10]; 
    for(int i = 1; i <= 3; i++) {
        x[i] = a[i]; y[i] = b[i]; 
    }
    if(aa) swap(x[1], y[1]); 
    if(bb) swap(x[2], y[2]); 
    if(cc) swap(x[3], y[3]); 
    if(x[2] > x[1] || y[2] > y[1]) return 0; 
    if(x[3] > x[1] || y[3] > y[1]) return 0; 
    if(x[2] + x[3] <= x[1]) return 1; 
    if(y[2] + y[3] <= y[1]) return 1; 
    return 0; 
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
    for(int i = 1; i <= 3; i++) {
        scanf("%d%d", &a[i], &b[i]); 
    }
    int flag = 0; 
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            for(int k = 0; k <= 1; k++) {
                int tmp = test(i, j, k); 
                if(tmp) flag = 1; 
            }
        }
    }
    if(flag) puts("YES"); 
    else puts("NO"); 

    return 0; 
}