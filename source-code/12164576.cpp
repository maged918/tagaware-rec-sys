//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

#define inc(i, a, b)    for(lli i=a; i<b; ++i)
#define inci(i, a, b)   for(lli i=a; i<=b; ++i)
#define dec(i, a, b)    for(lli i=a; i>b; --i)
#define deci(i, a, b)   for(lli i=a; i>=b; --i)

#define pll pair<lli, lli>

#define pb  push_back
#define mt  make_tuple
#define mp  make_pair

#define inp(a)          cin >> a
#define inp2(a, b)      cin >> a >> b
#define inp3(a, b, c)   cin >> a >> b >> c

#define fastScan ios_base::sync_with_stdio(false); cin.tie(NULL);

#define ll long long int
#define lli long long int


int main()
{
    fastScan;
    ll n, tmp, ans = 1;
    cin >> n;
    inc(i, 0, n){
        cin >> tmp;
        if(tmp==1)
            ans = -1;
    }
    cout << ans << endl;

    return 0;
}
