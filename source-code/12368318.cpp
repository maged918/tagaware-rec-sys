//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int NX=1000006,oo=0x7fffffff;
set<int> S,Si;
int A;
int f(int n){
    if(n<=A)return n/A;
    return (n+1)/(A+1);
}
int main(){
    int N,K,n,M,x;
    scanf("%d %d %d",&N,&K,&A);
    n=f(N);
    
    S.insert(0); Si.insert(0);
    S.insert(N+1); Si.insert(0-N-1);
    
    scanf("%d",&M);
    for(int i=1;i<=M;i++){
        scanf("%d",&x);
        int l,u;
        if(S.find(x)!=S.end())continue;
        if(Si.find(0-x)!=Si.end())continue;
        u=*S.upper_bound(x);
        l=*Si.upper_bound(0-x);l=0-l;
        //printf("%d %d %d\n",l,x,u);
        //printf("%d %d %d %d\n",n,f(x-l-1),f(u-l-1),f(u-x-1));
        n=n-f(u-l-1)+f(u-x-1)+f(x-l-1);
        if(n<K){
            printf("%d\n",i);
            return 0;
        }
        Si.insert(0-x);
        S.insert(x);
    }
    printf("-1\n");
    return 0;
}