//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j = 0, p = 0, n, a, l = 0, r = 0, m = 0;
    cin >> n;
    int b[n + 1], e[n + 1], c[n + 1];
    map<int, int> k;

    //memset(k, 0, sizeof(k));
    memset(b, 0, sizeof(b));
    memset(e, 0, sizeof(e));
    memset(c, 0, sizeof(c));

    for(int i = 1; i <= n; i++) {
        cin >> a;

        if(k.count(a)) {
            j = k[a];
        } else {
            j = ++p;
            k.insert(pair<int, int>(a, j));
        }


        /*
        for(j = 1; k[j] != 0; j++ ) {
            if(k[j] == a)
                break;
        }
        k[j] = a;
        */

        if(b[j] == 0) {
            b[j] = i;
        } else {
            e[j] = i;
        }

        c[j]++;
    }

    for(int i = 1; i < n; i++) {
        if(b[i] != 0) {
            if(e[i] == 0)
                e[i] = b[i];
        }

        if(c[i] > m || (c[i] == m && e[i] - b[i] < r - l)) {
            m = c[i];
            l = b[i];
            r = e[i];
        }
    }

    cout << l << " " << r << endl;
}
