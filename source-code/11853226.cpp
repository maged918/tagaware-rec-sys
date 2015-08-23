//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef int num;
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")
#else
#define debug(...) //
#endif

#define N 

int n, s, d;
int mini[3], maxi[3], val[3];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
        scanf("%d %d", mini+i, maxi+i);
    
    s = 0;
    for (int i = 0; i < 3; i++) {
        s += maxi[i];
        val[i] = maxi[i];
    }

    for (int i = 2; i >= 0; i--) {
        d = min(s-n, val[i] - mini[i]);
        s -= d;
        val[i] -= d;
    }

    printf("%d %d %d\n", val[0], val[1], val[2]);
}
