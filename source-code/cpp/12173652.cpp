//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <climits>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#define Lson Ls, L, mid
#define Rson Rs, mid+1, R
#define sqr(x) ((x)*(x))
using namespace std;
void in(int &x){
    char ch; int minus = 0;
    while (ch=getchar(), (ch<'0'||ch>'9') && ch!='-');
    if (ch == '-') minus = 1, x = 0;
    else x = ch-'0';
    while (ch=getchar(), ch>='0'&&ch<='9') x = x*10+ch-'0';
    if (minus) x = -x;
}
void out(int x){
    char hc[30];int len, minus=0;
    if (x<0) minus = 1, x = -x;
    len = 0; hc[len++] = x%10+'0';
    while (x/=10) hc[len++] = x%10+'0';
    if (minus) putchar('-');
    for (int i=len-1; i>=0; i--) putchar(hc[i]);
}

int c[10];
inline int f(int x){
    int w = x+x-1;
    return (1+w)*x/2;
}
int main(){
    for (int i=1; i<=6; i++) in(c[i]);
    int x = c[3] + c[2] + c[4];
    int ans = f(x);
    for (int i=2; i<=6; i+=2)
        ans -= f(c[i]);
    printf("%d\n", ans);
    return 0;
}
