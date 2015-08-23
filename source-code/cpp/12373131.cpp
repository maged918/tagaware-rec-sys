//Language: GNU C++11


# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# include <string>
# include <cstring>
# include <vector>
# include <set>
# include <map>
# include <queue>

using namespace std;

const int N = 1e6 + 5;

int n, k, a;
int m;
int hit, cnt;
set<int> s;


int main() {
#ifdef _DEBUG
    freopen("in", "r", stdin); freopen("out", "w", stdout);
#endif
    scanf("%d %d %d %d", &n, &k, &a, &m);
    cnt = (n + 1) / (a + 1);
    s.insert(0);
    s.insert(n + 1);
    for (int i = 0; i < m; i++){
        scanf("%d", &hit);
        auto it = s.lower_bound(hit);
        
        int y = *it;
        //cout << *it << " ";
        it--;
        //cout << *it << endl;
        int x = *it;


        cnt -= (y - x) / (a + 1);
        cnt += (hit - x) / (a + 1);
        cnt += (y - hit) / (a + 1);

        if (cnt < k){
            cout << i + 1;
            return 0;
        }

        s.insert(hit);
    }
    cout << -1;
    
    return 0;
}