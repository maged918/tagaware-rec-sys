//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
#define maxn 111
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int l,r;
    l=m-1; r=n-m;
    if(n==1&&m==1) printf("1\n");
    else if(l>=r) printf("%d\n",m-1);
    else printf("%d\n",m+1);
}