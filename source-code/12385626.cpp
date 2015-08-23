//Language: GNU C++


/* Supto
   Dept. Of CSE
   University Of Dhaka
*/
//#include<bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

#define pb push_back
#define ins insert
#define ff first
#define ss second
#define ll long long int
#define llu long long unsigned
#define sss stringstream
#define oss ostringstream
#define iss istringstream
#define pii pair<int,int>
#define _sq(x) ((x)*(x))
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define mem(a) memset(a,0,sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
#define ctz(x) __builtin_ctz(x) //number of trailing zeroes in a digit
#define ctzl(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(x)
#define clzl(x) __builtin_clzll(x) //number of leading zeroes in a digit
//If Long Long (mask & (1LL << k))
#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))
#define set0(mask ,k) (mask & (~(1<<k)))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;
#define pi acos(-1.0)
#define inf (1<<30)
#define eps 1e-9
#define MAX 200005
#define MAXL 15

//const ll mod = 1000003;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};
map <ll, ll> _map;
ll ar[MAX],lft[MAX],rgt[MAX];
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    //ios_base::sync_with_stdio(false);
    ll n, k, i;
    scanf("%lld %lld", &n, &k);
    for(i = 0; i <n; i++) scanf("%lld", &ar[i]);
    for(i = 0; i < n; i++)
    {
        if(ar[i]%k == 0) lft[i] = _map[ar[i]/k];
        _map[ar[i]]++;
    }
    _map.clear();
    for(i = n-1; i >= 0; i--)
    {
        rgt[i] = _map[ar[i]*k];
        _map[ar[i]]++;
    }
    ll ans = 0;
    for(i = 0; i < n; i++) ans += (lft[i]*rgt[i]);
    printf("%lld\n", ans);
    return 0;
}

	 				  					  	  			 	  	  	