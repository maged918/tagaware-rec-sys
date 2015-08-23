//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <iomanip>
using namespace std;

typedef long long int ll;
typedef long double ldouble;

#define PI acos(-1)
#define EPS 1e-7
#define INF 0x3f3f3f3f
#define endl "\n"

ll escolhe(ll a)
{
    ll result = a*(a-1)*(a-2);
    return result/6;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, k, input;
    map<ll, ll> c, a;
    
    ll result=0;
    cin >> n >> k;
    while(n-- > 0)
    {
        cin >> input;
        if(input%k==0 && k!=1)
        {
            ll temp=input/k;
            if(temp%k==0)
                result += a[temp];
            a[input]+=c[temp];
        }
        c[input]++;
    }
    if(k==1)
    {
        for(map<ll, ll>::iterator it = c.begin(); it != c.end(); it++)
            if(it->second > 2)
                result += escolhe(it->second);
    }
    cout << result << endl;
    
    return 0;
}

