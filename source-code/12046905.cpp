//Language: GNU C++


#include <stdio.h>
#include <map>

using namespace std;

map<int, int> mp, beg, end;
int times=0;
int l, r;

int main() {
    
    int n;
    scanf(" %d", &n);
    
    for(int i=0; i<n; i++) {
        int a;
        scanf(" %d", &a);
        
        mp[a]++;
        end[a] = i+1;
        if(mp[a]==1) beg[a] = i+1;
    }
    
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        int v = it->first;
        int t = it->second;
        int b = beg[v];
        int e = end[v];
        
        if(t > times || t==times && e-b < r-l) {
            times = t;
            l = b;
            r = e;
        }
    }
    
    printf("%d %d\n", l, r);
    
    return 0;
}