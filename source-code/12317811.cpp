//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

#define onlylove "My Sky"
#define mysky "TT"

#define X first
#define Y second
#define sz(A) int(A.size())
#define mpair make_pair
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1 )
#define sqr(x) ((x)*(x))


typedef long long ll;
typedef pair<int , int> pt;

const int OnlineJudge = 1;
const int maxc = 200000+1912;
const int maxn = 1000+1912;
const ll md = 1000LL*1000*1000+7;

pt a[maxn];
ll gt[maxc];
int h , w , n;

ll moduloReverse(ll a) {
    ll xa = 1 , xb = 0 , xr = 0;
    ll m = md;
    while (m > 0) {
        ll q = a / m;
        ll r = a % m;
        xr = xa - q*xb;
        xa = xb;xb = xr;
        a = m; m = r;
    }
    return xa;
}

void Init() {
    gt[0] = 1;
    for (int i = 1 ; i <= 200000+19; i++)
        gt[i] = (gt[i-1]*ll(i))%md;
}

int C(int k , int n) {
    return (gt[n] * moduloReverse(gt[n - k] * gt[k] % md))%md;
}

ll f[maxn][2];

ll get(const int j , const int i) {
    int dx = a[i].X - a[j].X;
    int dy = a[i].Y - a[j].Y;
    return C(dx , dx + dy);
}

void Solve() {
    a[0] = pt(1 , 1);
    a[n+1] = pt(h , w);
    sort(a , a + 2 + n);
    f[0][0] = 1;
    for (int i = 1 ; i <= n + 1 ; i++) {
        for (int j = 0 ; j < i; j++)
           if (a[j].X <= a[i].X && a[j].Y <= a[i].Y) {
              f[i][0] += f[j][1] * get(j , i)%md; f[i][0]%=md;
              f[i][1] += f[j][0] * get(j , i)%md; f[i][1]%=md;
           }
    }
    ll ans = f[n+1][1] - f[n+1][0];
    ans%=md; if (ans < 0) ans+= md;
    printf("%I64d\n",ans);
}

int main()
{
    std ::ios_base::sync_with_stdio(false);
    cin.tie(0);

    if (OnlineJudge){
    } else freopen("input.inp","r",stdin);

    scanf("%d%d%d",&h,&w,&n);
    for (int i = 1 ; i <= n ; i++)
        scanf("%d%d",&a[i].X , &a[i].Y);

    Init();
    Solve();

    return 0;
}
