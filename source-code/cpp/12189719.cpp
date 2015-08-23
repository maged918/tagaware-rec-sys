//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define display(arr,s,e) for(i=s; i<=e; i++) cout<<arr[i]<<" ";
#define mset(arr,x) memset(arr,x,sizeof(arr))

#define MOD 1000000007
#define epsilon 0.000000000001
#define I_MAX 9223372036854775807
#define I_MIN -9223372036854775807

#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)
#define endl "\n"

#define ll long long
#define mid(a,b) ((a)+((b-a)/2))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// Useful STL commands:
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define si set<int>
#define vi vector<int>
#define ii pair<int,int>
#define sii set<ii>
#define vii vector<ii>
#define all(c) c.begin(),c.end()
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)

#define DEBUG
// debugging
#ifdef DEBUG
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)        cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

ll gcd(ll a, ll b)
{
    if( (a == 0) || (b == 0) )
        return a + b;
    return gcd(b, a % b);
}

ll pow_mod(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return
    res;
}

string st1, st2;

bool solve(ll idx, ll idy, ll len)
{
   if( len%2 )
   {
      if( st1.substr(idx, len)==st2.substr(idy, len) )
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }
   else
   {
      if( (solve(idx, idy+len/2, len/2)) && (solve(idx+len/2, idy, len/2)) )
      {
         return 1;
      }
      if( (solve(idx, idy, len/2)) && (solve(idx+len/2, idy+len/2, len/2)) )
      {
         return 1;
      }

      return 0;
   }
}

int main()
{
        #ifndef  ONLINE_JUDGE
            freopen("input.txt","r",stdin);
        #endif

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        ll T, i, j, N;

        cin >> st1 >> st2;
        if( (st1.length()%2)  != 0 )
        {
           if( st1==st2 )
           {
               cout << "YES";
           }
           else
           {
               cout << "NO";
           }
        }
        else
        {
           if( solve(0, 0, st1.length()) )
           {
               cout << "YES";
           }
           else
           {
               cout << "NO";
           }
        }

        return 0;
}
