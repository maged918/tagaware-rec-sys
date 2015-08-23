//Language: GNU C++


/***********************************************
 ** problem ID  : cf_#314C.cpp
 ** create time : Thu Aug 06 11:56:26 2015
 ** auther name : xuelanghu
 ** auther blog : blog.csdn.net/xuelanghu407
 **********************************************/

#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
long long a[200010];
long long c[200010];

map<long long, long long>m;

int main () {
    m.clear();
    scanf ("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf ("%I64d", &a[i]);
        m[a[i]]++;
    }
    
    for (int i=0; i<n; i++) {
        m[a[i]]--;
        c[i] = m[k * a[i]];
    }
    
    
    m.clear();
    for (int i=0; i<n; i++) {
        m[a[i]] += c[i];
    }
    long long ans = 0;
    for (int i=0; i<n; i++) {
        m[a[i]] -= c[i];
        ans += m[k*a[i]];
    }
    
    printf ("%I64d\n", ans);
    
    return 0;
}