//Language: GNU C++11


#include<bits/stdc++.h>

using namespace std;

int viz[100005], s[100005], a[100005], freq[100000];


void mult(int x, int dist) {
    if(x < 100005 && x > 0) {
        viz[x]++;
        s[x] += dist;
        mult(2 * x, dist + 1);
    }
}

void divide(int x, int dist) {
    if(x > 0) {
        viz[x]++;
        s[x] += dist;
        if(x  % 2 == 0) {
            divide(x / 2, dist + 1);
        } else {
            divide(x / 2, dist + 1);
            mult((x / 2) * 2, dist + 2);
        }
    }
}
int main()
{
    int n, x;

    cin >> n;

    for(int i = 0; i < n; ++i){
       cin >> x;
       viz[x]++;
       mult(2 * x, 1);
       divide(x / 2, 1);
       if(x % 2 == 1)
        mult((x / 2) * 2, 2);
    }
    int minim = 1000000000, aux;
    for(int i = 1; i <= 100000; ++i) {
        if(viz[i] == n) {
            if(s[i] < minim)
                minim = s[i];
        }
    }

    cout << minim;


}
