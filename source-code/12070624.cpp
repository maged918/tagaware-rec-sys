//Language: GNU C++


//Abinash Ghosh
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cassert>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 100007
#define EPS 1e-9
int vis[100005];
int cnt[100005];
int f[100005];

int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int n,m;
    scanf("%d",&n);
    FOR(i,1,n)
    {
        scanf("%d",&m);
        queue<pii >q;
        q.push(mp(m,0) );
        while(!q.empty())
        {
            int v=q.front().x;
            int o=q.front().y;
            q.pop();
            if(v<100005&&vis[v]!=i)
            {
                vis[v]=i;
                f[v]++;
                cnt[v]+=o;
                q.push(mp(v<<1,o+1));
                q.push(mp(v>>1,o+1));
            }
        }
    }
    int ans=100000000;
    FOR(i,0,100000)
        if(f[i]==n)
            ans=min(ans,cnt[i]);
    printf("%d\n",ans);
    return 0;
}






