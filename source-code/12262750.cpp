//Language: MS C++


#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <memory.h>
#include <utility>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

#define y1 _sfjksdjfdskjf

const long long MAXVAL = 1000000000000000000LL;
const long long MINVAL = -1000000000000000000LL;

double sqr(double a)
{
    return a * a;
}


//priority_queue <int, vector<int>, greater<int> > q;

int a[1000001];
int l[1000001];
int r[1000001];
int n;
int ai;

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    for (int i = 0; i < 1000001; ++i)
    {
        a[i] = 0;
        l[i] = -1;
        r[i] = -1;
    }

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        ai--;
        a[ai]++;

        if (l[ai] == -1)
            l[ai] = i;
        r[ai] = i;
    }

    int max = 0;
    int min = 10000000;
    int ml = 10000000;
    int mr = 0;

    for (int i = 0; i < 1000001; ++i)
    {
        if (a[i] > max)
        {
            max = a[i];
            min = r[i] - l[i];
            ml = l[i] + 1;
            mr = r[i] + 1;
        }
        if (a[i] == max)
        {
            if (min > r[i] - l[i])
            {
                min = r[i] - l[i];
                ml = l[i] + 1;
                mr = r[i] + 1;
            }
        }
    }
    
    cout << ml << " " << mr << endl;

    return 0;
}