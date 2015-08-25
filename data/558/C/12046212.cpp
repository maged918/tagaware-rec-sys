//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 100005

int n, a[maxn], sum[maxn], x;
bool flag[maxn];

int cal(int d){
    int res = 0;
    For(i, 1, n){
        int temp = a[i];
        while(true){
            if(temp == d) break;
            res++;
            if(!flag[temp] || temp > d){
                temp >>= 1;
            } else temp += temp;
        }
    }
    return res;
}

int main(){
//  freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ms(sum, 0);
    For(i, 1, n){
        cin >> a[i];
        int temp = a[i];
        while(temp){
            if(temp & 1) sum[temp]++;
            temp >>= 1;
        }
    }

    int x = -1;
    For(i, 1, maxn - 1) if(sum[i] == n) x = i;
    ms(flag, 0);
    for(int i = x; i < maxn; i += i) flag[i] = 1;
    int res = inf;
    for(int i = x; i < maxn; i += i) res = min(res, cal(i));
    cout << res << endl;

    return 0;
}
