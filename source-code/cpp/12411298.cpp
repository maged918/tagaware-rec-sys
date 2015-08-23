//Language: GNU C++


/*
*Sourav Sen Tonmoy
*University of Dhaka
*/

#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)

#define mem(x,y) memset(x,y,sizeof(x));
#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%I64d", &x)
#define sdll(x, y) scanf("%I64d %I64d", &x, &y)
#define sdlll(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%I64d\n", x)
#define pfll(x, y) printf("%I64d %I64d\n", x, y)
#define pflll(x, y, z) printf("%I64d %I64d %I64d\n", x, y, z)

#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

int setBit(int N,int pos) { return N=N | (1<<pos); }
int resetBit(int N,int pos) { return N= N & ~(1<<pos); }
bool checkBit(int N,int pos) { return (bool)(N & (1<<pos)); }

using namespace std;

typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


LL n, k, kk;
map <LL, LL> mapp[4];

int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    LL i, temp, x, ans=0ll;

    sdll(n, k);
    kk = k*k;
    rep(i, n) {
        sdl(temp);

        if(temp%kk == 0ll) {
            if(mapp[2].find(temp/k) == mapp[2].end()) x = 0;
            else x = mapp[2][temp/k];
            if(mapp[3].find(temp) == mapp[3].end()) mapp[3][temp] = x;
            mapp[3][temp] += x;
            ans += x;
        }

        if(temp%k == 0ll) {
            if(mapp[1].find(temp/k) == mapp[1].end()) x = 0;
            else x = mapp[1][temp/k];
            if(mapp[2].find(temp) == mapp[2].end()) mapp[2][temp] = x;
            else mapp[2][temp] += x;
        }

        if(mapp[1].find(temp) == mapp[1].end()) mapp[1][temp] = 1;
        else mapp[1][temp]++;
    }
    pfl(ans);

    return 0;
}