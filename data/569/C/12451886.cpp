//Language: GNU C++11


 /* Author: happywu 
 *  File: c.cpp
 *  Create Date: 2015-08-11
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
const int maxn = 1200010;
int a[10],rub[maxn],pi[maxn],p,q;
bool pd(int x){
    if(x<10&&x>0)return 1;
    int tot=0;
    while(x){
        a[++tot]=x%10;
        x/=10;
    }
    for(int i=1;i<=tot;i++)
        if(a[i]!=a[tot-i+1])return 0;
    return 1;
}
bool pd_prime(int x){
    int k=sqrt(x);
    for(int i=2;i<=k;i++)
        if(x%i==0)return 0;
    return 1;
}
int main(int argc, char* argv[]){
    //freopen("a.in","r",stdin);
    rub[0]=0;
    for(int i=1;i<=1200000;i++)
        if(pd(i))rub[i]=rub[i-1]+1;
        else rub[i]=rub[i-1];
    scanf("%d%d",&p,&q);
    pi[1]=0;
    for(int i=2;i<=1200000;i++)
        if(pd_prime(i))pi[i]=pi[i-1]+1;
        else pi[i]=pi[i-1];
    if(p<=q){
        for(int i=40;i>=1;i--){
            if(q*pi[i]<=p*rub[i]){
                cout<<i<<endl;
                return 0;
            }
        }
    }else{
        for(int i=1200000;i>=1;i--){
            if(q*pi[i]<=p*rub[i]){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    puts("Palindromic tree is better than splay tree");

    return 0;
}

