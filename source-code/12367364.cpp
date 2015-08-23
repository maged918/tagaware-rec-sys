//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <bitset>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <list>
#include <numeric>
#include <iterator>


using namespace std;

#define pb push_back
#define mp make_pair
#define LSOne(S) (S & (-S))
#define Oo 2147483647
#define EPS 1e-9
#define MOD 1000000000 + 7
#define PI acos(-1)

typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;

int read() { int x; scanf("%d", &x); return x; }

int main()
{
    int n = read();
    int a[100000];
    int i, mn, mx, x, y;
    for(i=0;i<n;i++)
    {
        a[i] = read();
    }
    for(i=0;i<n;i++)
    {
        x = a[i];
        y = a[0];
        mx = -Oo;
        if(x > 0 && y > 0 || x < 0 && y < 0)
        {
            y = abs(x - y);
            if(y > mx) mx = y;
        }
        else
        {
            if(x < 0) x = -x;
            if(y < 0) y = -y;
            y += x;
            if(y > mx) mx = y;
        }
        x = a[i];
        y = a[n-1];
        if(x > 0 && y > 0 || x < 0 && y < 0)
        {
            y = abs(x - y);
            if(y > mx) mx = y;
        }
        else
        {
            if(x < 0) x = -x;
            if(y < 0) y = -y;
            y += x;
            if(y > mx) mx = y;
        }
        mn = Oo;
        if(i)
        {
            x = a[i];
            y = a[i-1];
            if(x > 0 && y > 0 || x < 0 && y < 0)
            {
                y = abs(x - y);
                if(y < mn) mn = y;
            }
            else
            {
                if(x < 0) x = -x;
                if(y < 0) y = -y;
                y += x;
                if(y < mn) mn = y;
            }
        }
        if(i + 1 < n)
        {
            x = a[i];
            y = a[i+1];
            if(x > 0 && y > 0 || x < 0 && y < 0)
            {
                y = abs(x - y);
                if(y < mn) mn = y;
            }
            else
            {
                if(x < 0) x = -x;
                if(y < 0) y = -y;
                y += x;
                if(y < mn) mn = y;
            }
        }
        printf("%d %d\n", mn, mx);
    }

    return 0;
}
