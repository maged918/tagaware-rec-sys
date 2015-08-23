//Language: GNU C++


/// The Budweiser ///
#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9+9;
const double pi = M_PI;
const double ep = 1e-9;

    int a[200][200];
    int d[200];

main() {
    ios::sync_with_stdio(false);
    //freopen("in.in","r",stdin); freopen("ou.ou","w",stdout);
    int n,m;
    cin>>n>>m;
    foru(i,1,m)
        foru(j,1,n)
            cin>>a[i][j];

    foru(i,1,n) d[i]=0;
    foru(i,1,m) {
        int Max = -1;
        int t = 0;
        foru(j,1,n) {
            if (a[i][j]>Max) {
                Max = a[i][j];
                t = j;
            }
        }
        d[t]++;
    }

    int Max = -1,t=0;
    foru(i,1,n) if (d[i]>Max) {
        Max = d[i];
        t = i;
    }
    cout<<t;

    return 0;
}
