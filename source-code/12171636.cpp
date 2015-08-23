//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
using namespace std;
int a[8];
inline void solve(){
    for(int i=1;i<=6;i++) scanf("%d",&a[i]);
    int total=0,noww=a[1],last=a[1],aa=0,bb=0;
    for(int i=1;i<=a[2]+a[3];i++) {
        if(i>a[6]) aa=1;
        if(i>a[2]) bb=1;
        if(aa==0&&bb==0) noww++;
        else if(aa==1&&bb==1) noww--;
        //printf("%d %d\n",last,noww);
        total+=(noww+last);
        last=noww;
    }
    printf("%d\n",total);
}
int main(){
    //freopen("cf3132C.in","r",stdin);freopen("cf3132C.out","w",stdout);
    solve();
    return 0;
}
