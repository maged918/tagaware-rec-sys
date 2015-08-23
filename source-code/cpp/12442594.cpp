//Language: GNU C++11


//
//  main.cpp
//  A
//
//  Created by nicomazz on 24/06/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <bitset>

using namespace std;

#define TEST
#define MAXN 100010

typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef  long long ll;

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

#define iOS ios_base::sync_with_stdio(false)
#define error(x) cerr << #x << " = " << (x) <<endl
#define all(x) (x).begin(), (x).end()
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#define gc getchar

#define pi 3.141592654
#define EPS 1e-7

inline void scanInt(int &x)
{
    register char c=gc();
    x = 0;
    bool neg = false;
    while( c<48 || c>57) {if (c == '-')neg = true; c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}
vector<int*> bad;

int num[MAXN];
bool pres[MAXN];

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
// B
    int N;

    scanInt(N);

    for (int i = 0; i < N; i++)
    {
        scanInt(num[i]);
        if ( num[i] < 1 || num[i] > N)
            bad.push_back(&num[i]);
        else if ( num[i] >= 1 && num[i] <= N)
        {
            if ( pres[num[i]])
                bad.push_back(&num[i]);
            else pres[num[i]] = true;
        }
    }
    vector<int> liberi;
    for (int i = 1; i <= N; i++)
        if (!pres[i]) liberi.push_back(i);
    int i_lib = 0;
  for (int i = 0; i < bad.size(); i++)
  {
      *(bad[i]) = liberi[i_lib++];
  }
  for (int i = 0; i < N; i++)
    cout<<num[i]<<" ";
    return 0;
}
