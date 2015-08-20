//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int arr[100005];

int main()
{   set <int> s;
    int n,k,a,m,i,x;
    cin >> n >> k >> a;
    cin >> m;
    s.insert(0);
    s.insert(n+1);
    int cnt = (n+1)/(a+1);
    for (i = 1; i <= m; i++) {
        cin >> x;
        set<int>::iterator it = s.upper_bound(x);
        int r = *(it--);
        int l = *it;
        cnt -= ((r-l)/(a+1)-(x-l)/(a+1)-(r-x)/(a+1));
        if (cnt < k) {
            cout << i << endl;
            return 0;        
        }
        s.insert(x);
    }
    cout << -1 << endl;
    return 0;
}
