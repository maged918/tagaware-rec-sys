//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int n, k, a;

int main () {
    set<int>::iterator l, r, ll;
    cin >> n >>k >> a;
    set<int>ss;
    ss.insert(0);
    ss.insert(n+1);
    int ok = 0;
    int ti, xx= 0;
    cin >>ti;
    for(int i = 0, x; i <ti; i++){
        cin >> x;
        r = ss.lower_bound(x);
        l = ss.lower_bound(x);
        int L = *(--l), R = *r;
        int d = (R-L), dl = x-L, dr = R-x;
        xx += dl/(a+1) + dr/(a+1);
        if(i) xx -= d/(a+1);
        if(xx < k) {ok = i+1; break;}
        ss.insert(x);
    }
    if(!ok) puts("-1");
    else cout<<ok <<endl;
}
