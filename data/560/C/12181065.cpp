//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f(i, k, n) for(int i = k; i < n; i++)
#define fd(i, k, n) for(int i = k; i >= n; i--)
#define ve vector
#define e '\n'
struct st{
    long long n, v;
    bool operator<(const st &other) const{ return n < other.n;}
};
ll fq( ll n){
    ll s = 0;
    for ( int i = 1; i <= n*2-1; i += 2)
        s += i;
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    ll n, m, a, b, c, d, maxi, mini, q;
    vector<ll> v(6);
    f(i, 0, 6)
         cin >> v[i];
    maxi = *max_element(v.begin(), v.end());
    f(i, 0, 6){
        if ( v[i] == maxi){
            int k = (i+1)%6, z = i-1;
            if ( z == -1)
                z = 5;
            q = v[i] + v[k] + v[z];
            ll s1 = v[k], s2 = v[(k+2)%6], s3 = v[((k+2)%6+2)%6];
            return cout << fq(q) - fq(s1) - fq(s2) - fq(s3), 0;
        }
    }
    return 0;
}
