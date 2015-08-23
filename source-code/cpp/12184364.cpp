//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x)

#define FOR(i,a,b)      for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b)     for(int i=(int)(b)-1;i>=(int)(a);i--)

#define gcd(a,b)  __gcd(a,b)
#define MOD       1000000007
#define EPS       1E-10

#define PI  acos(-1)

#define CASE(x)   cout << "Case #" << x << ": ";

LL fact[1000001];
LL modIF[1000001];

LL BigMod(LL a,LL b,LL mod)
{
      if(!b) return 1;
      LL x = BigMod(a,b/2,mod);
      x = (x*x)%mod;
      if(b&1) return (x*a)%mod;
      else return x;
}

LL modinv(LL a,LL mod)
{
      return BigMod(a,mod-2,mod);
}

LL ncr(int n , int r)
{
    if(r < 0 || r > n) return 0;
    LL ret = fact[n];
    ret = (ret * modIF[r]) % MOD;
    ret = (ret * modIF[n-r]) % MOD;
    return ret;
}

vector<PII> arr;

int cmp(const PII &a , const PII &b)
{
    return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

LL F(int x1 , int y1 , int x2 , int y2)
{
    int a = x2 - x1;
    int b = y2 - y1;
    return ncr(a + b , a);
}

int main()
{
    fact[0] = 1;
    modIF[0] = 1;
    
    FOR(i,1,1000001) fact[i] = (fact[i-1] * i) % MOD;
    FOR(i,1,1000001) modIF[i] = modinv(fact[i] , MOD);

    int n,m;
    scanf("%d%d",&n,&m);
    int k;
    scanf("%d",&k);
    arr.resize(k);
    FOR(i,0,k) scanf("%d%d",&arr[i].first,&arr[i].second);
    arr.pb(mp(n,m));
    sort(all(arr) , cmp);
    vector<LL> ans;
    k += 1;
    FOR(i,0,k) ans.pb(F(1 , 1 , arr[i].first , arr[i].second));

    FOR(i , 0 , k - 1)
    {
        FOR(j , i + 1 , k)
        {
            if(arr[j].first < arr[i].first || arr[j].second < arr[i].second) continue;
            LL rem = (ans[i] * F(arr[i].first , arr[i].second , arr[j].first , arr[j].second)) % MOD;
            ans[j] = (ans[j] - rem) % MOD;
            ans[j] = (ans[j] + MOD) % MOD;
        }
    }
    cout << ans[k-1] << endl;
    return 0;
}