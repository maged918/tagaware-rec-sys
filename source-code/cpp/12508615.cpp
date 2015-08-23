//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n,m,a,mid;
    scanf("%lld %lld",&n,&m);
    if(n==1){
        printf("1\n");
        return 0;
    }
    if((m-1)>=(n-m)){
        a=m-1;
    }
    else{
        a=m+1;
    }
    printf("%lld\n",a);
    return 0;
}
