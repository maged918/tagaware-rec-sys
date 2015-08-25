//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <map>
#include <cstring>

using namespace std;

int main()
{
    long long int n, i, j, ct = 0, t, ty = 0, vac = 0, tt = 0;
    cin >> n;
    map <int, int> mp;
    long long int a[n], maxv = 0, sum[n], flag = 0;
    char c[n];
    for(i = 0; i < n; i++)
        cin >> c[i] >> a[i];

    memset(sum, 0, sizeof(sum));

    for(i = 0; i < n; i++) {
        if(c[i] != '-') {
            mp[a[i]]++;
            if(vac != 0)
                vac--;
            else
                tt++;
        }
        else {
            if(mp[a[i]] == 0) {
                    tt++;
                    vac++;

            }
            else {
                mp[a[i]]--;
                vac++;
            }
        }


    }
    cout << tt << endl;
    return 0;
}
