//Language: GNU C++11






//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <bitset>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define reveach(i, v) for (__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++ i)
#define REP(i,n) for ( int i=1; i<=int(n); i++ )
#define rep(i,n) for ( int i=0; i< int(n); i++ )
using namespace std;
typedef long long ll;
#define X first
#define Y second
typedef pair<int,int> pii;

template <class T>
inline bool RD(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void PT(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) PT(x / 10);
    putchar(x % 10 + '0');
}


int main(){
        int n,m;
        cin>>n>>m;
        if( n == 1 && m == 1){
                puts("1");
                return 0;
        }
        if(m <= n/2) {
                printf("%d\n",m+1);
        }else{
                printf("%d\n",m-1);
        }
}
