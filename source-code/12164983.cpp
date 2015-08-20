//Language: GNU C++11


#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
#define LL long long
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%I64d",&x)
#define all(x) x.begin(),x.end()
#define compress(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
template<class T> inline void umax(T &a,T b){if(a<b) a = b ;}
typedef pair<int, int> ii;
typedef pair<LL, LL> PII;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
#define vl vector<>
#define vi vector<int>
#define vii vector<ii>
#define vvl vector< vl >
#define vvi vector< vi >
#define vvii vector< vii >
#define sz size()
#define pb push_back
#define F first
#define S second
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repv(i,b,a) for(int i=(b);i>=(a);i--)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PDD pair<LL, LL>
#define LLD long double

const int maxn = 200000 + 10;
const int INF  = 1e9 + 7;
//const LL INF = 0x0123456789ABCDEFLL;
inline void solve(void){
        int n,x;
        cin>>n; 
        int f =0;
        rep(i,0,n){
            cin>>x;
            if(x==1)f=1;
        }
        if(f)cout << "-1";
        else cout <<"1";
}
void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main(int argc, const char * argv[]){
    //freopen("positive.in","r",stdin);
    //freopen("positive.out","w",stdout);
    init();
    solve();
    return 0;
}
