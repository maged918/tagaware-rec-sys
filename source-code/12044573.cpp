//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < (n); i++)
const int N = 140;

int n, x, a;
vector<pair<int, int> > dotN, dotP;

int main(){
    scanf("%d", &n);
    forn(i, n){
        scanf("%d %d", &x, &a);
        if(x > 0){
            dotP.push_back( {x, a} );
        }
        else {
            dotN.push_back( {-x, a} );
        }
    }
    sort(dotP.begin(), dotP.end());
    sort(dotN.begin(), dotN.end());
    int p, q;
    p = q = 0;
    // por derecha
    bool cnd = true;
    int best = -1, sum = 0;
    while(true){
        if(cnd){
            if(p == dotP.size()) break;
            sum += dotP[p].second;
            p++;
        }
        else {
            if(q == dotN.size()) break;
            sum += dotN[q].second;
            q++;
        }
        cnd = !cnd;
    }
    best = max(sum, best);
    cnd = false;
    p = q = sum = 0;
    while(true){
        if(cnd){
            if(p == dotP.size()) break;
            sum += dotP[p].second;
            p++;
        }
        else {
            if(q == dotN.size()) break;
            sum += dotN[q].second;
            q++;
        }
        cnd = !cnd;
    }
    best = max(sum, best);
    printf("%d\n", best);
    return 0;
}
