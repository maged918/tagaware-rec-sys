//Language: GNU C++


#pragma comment(linker, "/STACK:102400000,102400000")

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>
#include <strstream>

using namespace std;

#define N 400005
#define M 100005

#define NN (2<<18)
#define P ((479LL << 21) + 1)
#define G 3
#define NUM 20

#define INF  0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f

#define LL  long long
#define MOD 1000000007
#define pi acos(-1.0)
#define eps 1e-9

#define MID ((l + r)/2)
#define lx (x<<1)
#define rx ((x<<1)|1)

int base2[25];
int h[N],a[N];
int b[N];
int c[N];

void init(){
    base2[0] = 1;
    for(int i=1;i<=22;i++){
        base2[i] = base2[i-1] * 2;
    }
    for(int _i=0;_i<=400000;_i++){
        int i = _i;
        h[i] = 0;
        while(i){
            i>>=1;
            h[_i]++;
        }
    }
}
void output(int tmp){
    for(int i=20;i>=0;i--){
        if(tmp &(1<<i)){
            printf("%d",1 );
        }
        else{
            printf("%d",0 );
        }
    }
    puts("");
}
int main(){
    //freopen("in.txt","r",stdin);
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        int mx = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            mx = max(mx,h[a[i]]);
        }
        int ans = INF;
        for(int l=0;l<h[a[0]];l++){
            int _t = a[0]/base2[l];
            for(int r=0;r<=mx-h[a[0]]+1;r++){
                bool flag = true;
                int t = _t * base2[r];
                int step = l + r;
                for(int i=1;i<n;i++){
                    int type = 0;
                    int other = a[i];
                    int gap = abs(h[other] - (h[a[0]] - l + r));
                    if(h[other] >= h[a[0]] - l + r){
                        other /= base2[gap];
                    }
                    else{
                        other *= base2[gap];
                        type = 1;
                    }
                    if(other < 0 ){
                        flag = false;
                        break;
                    }
                    else {
                        int lowbit = t&(-t);
                        if(other/lowbit != t/lowbit){
                            flag = false;
                            break;
                        }
                    }
                    other = other - t;
                    if(type == 1){
                        if(other != 0){
                            step += (h[other] - gap)*2 + gap;  
                        }
                        else{
                            step += gap;
                        }
                    }
                    else{
                        step += 2*h[other];
                        step += gap;
                    }
                }
                if(flag){
                    ans = min(ans,step);
                }
            }

        }
        printf("%d\n",ans );
    }
    return 0;
}
