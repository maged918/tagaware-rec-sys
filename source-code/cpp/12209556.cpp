//Language: GNU C++


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL tomod=1000000007;

void extgcd(LL a,LL b,LL& d,LL& x,LL& y){
    if(!b){
        d=a;x=1;y=0;
    }else{
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

LL mod_inv(LL a,LL n){//a在模n意义下的逆元
    LL d,x,y;
    extgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

LL frac[200005];
LL inv[200005];

LL comb(int c,int take){
    LL ans=frac[c];
    ans=(ans*inv[take])%tomod;
    ans=(ans*inv[c-take])%tomod;
    return ans;
}

struct Point{
    int x,y;
    bool operator<(const Point &b)const{
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
}p[10005];

LL f[10005];

int main(){
    frac[0]=inv[0]=frac[1]=inv[1]=1;
    for(int i=2;i<=200000;i++){
        frac[i]=(frac[i-1]*i)%tomod;
        inv[i]=mod_inv(frac[i],tomod);
    }
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p,p+n);
    LL ans=comb(h+w-2,h-1);
    for(int i=0;i<n;i++){
        f[i]=comb(p[i].x+p[i].y-2,p[i].x-1);
        for(int j=0;j<i;j++){
            if(p[j].x<=p[i].x&&p[j].y<=p[i].y){
                f[i]=(f[i]-f[j]*comb(p[i].x-p[j].x+p[i].y-p[j].y,p[i].x-p[j].x))%tomod;
            }
        }
        ans=(ans-f[i]*comb(h-p[i].x+w-p[i].y,h-p[i].x))%tomod;
    }
    ans=(ans+tomod)%tomod;
    printf("%I64d\n",ans);
    return 0;
}
