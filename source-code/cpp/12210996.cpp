//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int mod = 1000000007;
const int N = 200010;
const int M = 2010;
typedef long long ll;

ll mul[N];

ll inverse(int a,int p){//
    if(a == 1) return 1;
    int r = p%a,k =  p/a;
    ll ret = (-k*inverse(r,p))%p;
    while(ret<0) ret+=p;
    return ret;
}

void init(){
     mul[0] = mul[1] = 1;
     for(int i = 2;i < N;i++) mul[i] = (mul[i-1]*(ll)i)%mod;
}

ll comb(int n,int m){
    if(m == 0) return 1;
    return (mul[n]*inverse((int)((mul[m]*mul[n-m])%mod),mod))%mod;
}

struct node{
    int x,y;
};

node rect[M];
bool cmp(node a,node b){
     if(a.x < b.x) return true;
     else if(a.x == b.x&&a.y<b.y) return true;
     return false;
}

ll dp[M];

int main()
{
    int h,w,n,x,y;
    init();
    cin>>h>>w>>n;
    memset(dp,0,sizeof(dp));
    for(int i = 0;i < n;i++){
        scanf("%d%d",&x,&y);
        rect[i].x = x;
        rect[i].y = y;
    }
    rect[n].x = h;
    rect[n].y = w;
    sort(rect,rect+n+1,cmp);
    x = rect[0].x;
    y = rect[0].y;
    dp[0] = comb(x+y-2,x-1);
    for(int i = 1;i <= n;i++){
        int x = rect[i].x,y = rect[i].y,r,c;
        for(int j = 0;j < i;j++){
            r = rect[j].x;
            c = rect[j].y;
            if(r<=x&&c<=y){
                dp[i] += dp[j]*comb(x+y-r-c,x-r);
                dp[i] %= mod;
            }
        }
        dp[i] = comb(x+y-2,x-1) - dp[i];
        while(dp[i]<0) dp[i] += mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
