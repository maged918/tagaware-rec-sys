//Language: GNU C++


#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
bool kiemtra(int x, int y, int x1, int y1) {
     if(x >= x1 && y >= y1) return true;
     if(y >= x1 && x >= y1) return true;
     return false;
}
int main(){
    //  freopen("in.txt","r",stdin);
    //  freopen("out.txt","w",stdout);
     int a, b, a1, b1, a2, b2;
     int check = 0;
     scanf("%d%d%d%d%d%d",&a,&b,&a1,&b1,&a2,&b2);

    check = check + kiemtra(a, b, a1 + a2, max(b1, b2));
    check = check + kiemtra(a, b, b1 + b2, max(a1, a2));
    check = check + kiemtra(a, b, a1 + b2, max(a2, b1));
    check = check + kiemtra(a, b, a2 + b1, max(a1, b2));
    if(check >= 1) printf("YES"); else printf("NO");
}
