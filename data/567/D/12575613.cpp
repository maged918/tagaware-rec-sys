//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

const int INF = (1e9+7);
int a;

int amount(int l, int r) {
    int len = r - l + 1;
    if (len < a) return 0;
    return (len + 1) / (a + 1);
}

int  main(){
    
//    freopen("in.in", "r", stdin);
//  freopen("", "w", stdout);

    int n, k;
    scanf("%d %d %d", &n, &k, &a);
    int m;
    scanf("%d", &m);

    set<pair<int, int> > s;
    s.insert(mp(n, 1));

    int num = amount(1, n);
    //set<pair<int, int> >::iterator wow = s.begin();
    //cerr << wow->snd << endl;

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        set<pair<int, int> >::iterator it = s.lower_bound(mp(x, -1));

        //it--;
        //cerr << it->frs << " " << it->snd << "\n";
        num -= amount(it->snd, it->frs);
        pair<int, int> curr = *it;
        //cerr << it->frs << " " << it->snd << " " << n;
        s.erase(it);
        num += amount(curr.snd, x - 1) + amount(x + 1, curr.frs);
        if (curr.snd <= x - 1) s.insert(mp(x - 1, curr.snd));
        if (x + 1 <= curr.frs) s.insert(mp(curr.frs, x + 1));
        
        if (num < k) { printf("%d", i + 1); return 0;}

    }     

    printf("-1");

    return 0;
}