//Language: GNU C++


#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = int (2e5+7);
             
int p, q, pal, prime, ans;
char c[500];

int main () {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);  

    cin >> p >> q;
    for(int i = 1; i <= 2000000; i ++) {
        itoa(i, c, 10);
        int t = i, l = 0, f = 0;
        while(t > 0)
            l ++, t /= 10;
        for(int j = 0; j < l / 2; j ++) 
            if(c[j] != c[l - j - 1]) 
                f = 1;
        if(!f)
            pal ++;
        t = 0;
        for(int j = 2; j <= sqrt(i); j ++)
            if(i % j == 0) {
                t = 1;
                break;
            }
        if(!t && i != 1)
            prime ++;
        if(prime * q <= pal * p) 
            ans = i;
    }
    cout << ans;
    return 0;
}