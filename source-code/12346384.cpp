//Language: GNU C++


#include<stdio.h>
#include<algorithm>
#define V 100001
#define D 200001
#define M 1000000007
using namespace std;

struct Point{
    int x;
    int y;
    void read(){
        scanf("%d%d",&x,&y);
    }
    bool operator < (const Point& rhs)const{
        if(x!=rhs.x)
            return x<rhs.x;
        return y<rhs.y;
    }
    bool operator <= (const Point& rhs)const{
        return x<=rhs.x && y<=rhs.y;
    }
};

long long fact[V<<1];
long long inv[V];
long long dp[2000];
Point data[2000];

long long pow(long long b,int p){
    long long ret=1;
    while(p){
        if(p&1)
            ret*=b, ret%=M;
        b*=b, b%=M;
        p>>=1;
    }
    return ret;
}

void factGen(){
    int i;
    fact[0]=1;
    for(i=1;i<D;i++)
        fact[i] = (fact[i-1]*i)%M;
}

void invGen(){
    int i;
    for(i=0;i<V;i++)
        inv[i] = pow(fact[i],M-2);
}

int main(){
    int i,j,h,w,n;
    int getX,getY;
    long long ans, sub, tmp;
    factGen();
    invGen();
    scanf("%d%d%d",&h,&w,&n);
    for(i=0;i<n;i++)
        data[i].read();
    sort(data,data+n);
    for(i=0;i<n;i++){
        getX=data[i].x-1, getY=data[i].y-1;
        dp[i] = fact[getX+getY];
        dp[i] *= inv[getX], dp[i] %= M;
        dp[i] *= inv[getY], dp[i] %= M;
        for(j=0,sub=0;j<i;j++){
            if(data[j]<=data[i]){
                getX=data[i].x-data[j].x, getY=data[i].y-data[j].y;
                tmp = dp[j];
                tmp *= fact[getX+getY], tmp %= M;
                tmp *= inv[getX], tmp %= M;
                tmp *= inv[getY], tmp %= M;
                sub += tmp, sub %= M;
            }
        }
        dp[i] -= sub;
        dp[i] %= M;
        if(dp[i]<0)
            dp[i] += M;
    }
    /*printf("\n");*/
    ans = fact[h+w-2];
    ans *= inv[h-1], ans %= M;
    ans *= inv[w-1], ans %= M;
    for(i=0,sub=0;i<n;i++){
        getX=h-data[i].x, getY=w-data[i].y;
        dp[i] *= fact[getX+getY], dp[i] %= M;
        dp[i] *= inv[getX], dp[i] %= M;
        dp[i] *= inv[getY], dp[i] %= M;
        sub += dp[i], sub %= M;
    }
    ans -= sub;
    ans %= M;
    if(ans<0)
        ans += M;
    printf("%lld\n",ans);
    return 0;
}
