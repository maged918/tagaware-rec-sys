//Language: GNU C++11


#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define MAXQ 100010

int h, q, topa;
ull two[100];
pair<ull, ull> a[2*MAXQ];

void Debug()
{
}

void Wrong()
{
    cout << "Game cheated!\n";
    exit(0);
}

void Undefined()
{
    cout << "Data not sufficient!\n";
    exit(0);
}

void Read()
{
    cin >> h >> q;
}

void Add(ull from, ull to)
{
    if(from <= to)
        a[++topa] = mp(from, to);
}

void Solve()
{
    int height;
    bool op;
    ull from, to;
    two[0] = 1;
    for(int i=1; i<=h; ++i)
        two[i] = two[i-1]*2;
    for(int i=1; i<=q; ++i)
    {
        cin >> height >> from >> to >> op;
        if(op == 0)
            Add(two[h-height]*from, two[h-height]*to + two[h-height] -1);
        else
        {
            Add(1, two[h-height]*from-1);
            Add(two[h-height]*to + two[h-height], two[h]);
        }
    }

    sort(a+1, a+topa+1);

    ull last = two[h-1]-1;
    ull ans=0;
    for(int i=1; i<=topa; ++i)
    {
        if(a[i].X > last+1)
        {
            if(a[i].X - last > (ull)2)
                Undefined();
            if(ans > 0)
                Undefined();
            ans = a[i].X-1;
        }
        if(a[i].Y > last)
            last = a[i].Y;
    }
    if(two[h] > last+1)
    {
        if(two[h] - last > (ull)2)
            Undefined();
        if(ans > 0)
            Undefined();
        ans = two[h]-1;
    }

    if(ans == 0LL)
        Wrong();
    cout << ans << "\n";
}

int main()
{
    Read();
    Solve();
    Debug();
    return 0;
}
