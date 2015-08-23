//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>

using namespace std;

set<int>s;
int n,k,a,m;

int main()
{
    //freopen("test.inp","r",stdin);
    cin >> n >> k >> a;
    cin >> m;
    s.clear();
    s.insert(0);
    s.insert(n+1);
    int tp=(n+1)/(a+1),pos=0;
    bool fl=false;
    for (int i=1;i<=m;i++)
    {
        pos=i;
        int x;
        cin >> x;
        set<int>::iterator v;
        v=s.lower_bound(x);
        int r=*v;
        v--;
        int l=*v;
        tp=tp-(r-l)/(a+1)+(x-l)/(a+1)+(r-x)/(a+1);
        if (tp<k) {fl=true;break;}
        s.insert(x);
    }
    if (fl) cout << pos;
    else cout << -1;
    return 0;
}
