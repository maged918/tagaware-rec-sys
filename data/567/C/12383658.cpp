//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;
map<long long,long long> m,s;
int main(){
    long long i,n,k,a,ans=0;
    scanf("%lld %lld",&n,&k);
    for(i=0;i<n;i++){
        scanf("%lld",&a);
        if(a%k==0){
            ans += m[a/k];
            m[a] += s[a/k];
        }
        s[a] ++;
    }
    printf("%lld",ans);
    return 0;
}