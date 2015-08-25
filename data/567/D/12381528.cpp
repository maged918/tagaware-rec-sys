//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

#define READ(in)      freopen(in, "r", stdin)
#define WRITE(out)    freopen(out, "w", stdout)

#define FOR(i, s, e)  for(int i=s; i<=e; i++)
#define FOREACH(i,n)  for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
#define SCI(x)        scanf("%d", &x)
#define SCII(x, y)    scanf("%d %d", &x, &y)
#define SCIII(x, y, z) scanf("%d %d %d", &x, &y, &z)

#define SET(x, y)     memset(x, y, sizeof(x))
#define SORT(x)       sort(x.begin(), x.end());
#define REVERSE(x)    reverse(x.begin(), x.end())

#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define pii           pair<int, int>

#define DB(x)         cerr << #x << " = " << x << endl;
#define DBII(x, y)      cerr << #x << " = " << x << '\t' << #y << " = " << y << endl;
#define DBIII(x, y, z)   cerr << #x << " = " << x << '\t' << #y << " = " << y << '\t' << #z << " = " << z << endl;

#define MOD(x) x%10000007
#define MAX (long long unsigned) (1e18) + 7
#define Min(x, y) (x<=y) ? x : y
typedef long long ll;



int main()
{
    //READ("in.txt");
    int n, k, a, m, x;
    while(cin >> n >> k >> a){
        cin >> m;
        set<int> myset;
        myset.insert(0);
        myset.insert(n+1);
        int cnt = (n+1)/(a+1);
        int save=-1;
        bool flag = true;
        for(int i=0; i<m; i++){
            scanf("%d", &x);
            if(flag){
                myset.insert(x);
                auto in = myset.find(x);
                auto be = in;
                auto af = in;
                be--, af++;
                cnt -= (*af-*be)/(a+1);
                cnt += (*af-*in)/(a+1);
                cnt += (*in-*be)/(a+1);
                if(cnt < k) {
                    flag = false;
                    save = i+1;
                }
                //DB(cnt);
            }
        }
        cout << save << endl;

    }
    return 0;
}
