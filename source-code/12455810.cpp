//Language: GNU C++


// Made By Haireden Aibyn
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define fname ""
#define INF 2147483647
#define MOD 1000000007
#define sc scanf
#define pr printf
#define pb push_back
#define ex exit(0)
#define tim printf("%.4lf\n", (clock() * 1.) / CLOCKS_PER_SEC)
#define cas printf(""), ex;
#define y1 y4

typedef long long ll;
typedef unsigned long long ull;

int was[100500], a[100500];

int main () {
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);
    #endif  
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        was[a[i]]++;
    }
    int j = 1;
    while (was[j])
          j++;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= n) {
           if (was[a[i]] > 1) {
              was[a[i]]--;
              was[j]++;
              a[i] = j;
              while (was[j])
                    j++;
           }
        } else {
           was[j]++;
           a[i] = j;
           while (was[j])
                 j++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
