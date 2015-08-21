//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 2147483646;

int n;
int a[100004];

int diff(int x,int y) {
    if (x==y||x<0||y<0||x>=n||y>=n)
        return INF;
    else
        return abs(a[x]-a[y]);
}

int diff2(int x,int y) {
    if (x==y||x<0||y<0||x>=n||y>=n)
        return -INF;
    else
        return abs(a[x]-a[y]);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    
    for(int i=0;i<n;++i) {
        printf("%d ", i?min(diff(i,i-1),diff(i,i+1)):min(diff(i,n-1),diff(i,i+1)));
        printf("%d",max(diff2(i,0),diff2(i,n-1)));
        puts("");
    }
}