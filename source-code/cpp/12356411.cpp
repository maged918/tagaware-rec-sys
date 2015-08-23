//Language: GNU C++


#include <bits/stdc++.h>

#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, a, b) for(int i = (a); i <=(b); ++i)
#define Ford(i, a, b) for(int i = (a); i > (b); --i)
#define repd(i, a, b) for(int i = (a); i >=(b); --i)
#define forit(it,v) for(it=v.begin();it!=v.end();it++)
#define ms(a, v) memset(a, (v), sizeof(a))
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define ll long long
#define ld long double
#define ii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'
#define openfi freopen("in.tt","r",stdin)
#define openfo freopen("out.tt","w",stdout)

using namespace std;
const int maxn=100005;

int n,a[maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    int j;
    rep(i,1,n) if (a[i]>=0) j=i;
    rep(i,1,n)
    {
        int Max=INT_MIN,Min=INT_MAX;
        if (i==1)
        {
            Min=abs(a[1]-a[2]);
            Max=abs(a[1]-a[n]);
        }
        else
        if (i==n)
        {
            Min=abs(a[n]-a[n-1]);
            Max=abs(a[n]-a[1]);
        }
        else
        {
            Min=min(abs(a[i]-a[i+1]),abs(a[i]-a[i-1]));
            Max=max(abs(a[i]-a[1]),abs(a[n]-a[i]));
        }
        cout << Min << " " << Max << endl;
    }
    return 0;
}













