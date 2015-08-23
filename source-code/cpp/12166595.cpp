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

int a1, b1, a2, b2, a3, b3;
inline bool check(int a1, int b1, int a2, int b2){
    return a1>=a2&&b1>=b2;
}
inline bool solve(int a1, int b1, int a2, int b2, int a3, int b3){
    if (a1<a2 || b1<b2) return 0;
    if (check(a1-a2, b1, a3, b3)) return 1;
    if (check(a1, b1-b2, a3, b3)) return 1;
    return 0;
}
int c[10][10];
int main(){
    for (int i=1; i<=3; i++)
        for (int j=1; j<=2; j++)
            in(c[i][j]);
    bool flag = 0;
    for (int i=1; i<=2&&!flag; i++)
    for (int j=1; j<=2&&!flag; j++)
    for (int k=1; k<=2&&!flag; k++){
        if (solve(c[1][i], c[1][3-i], c[2][j], c[2][3-j], c[3][k], c[3][3-k])){
            flag = 1;
            break;
        }
    }
    if (flag) puts("YES");
    else puts("NO");
    return 0;
}

