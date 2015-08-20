//Language: MS C++


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<iterator>
#include<map>
#include<queue>
#include<cstdio>

using namespace std;
typedef long long ll;
typedef double db;
int N=50000000;

bool check(int n){
    int m=0, nn=n;
    while (n){m=m*10+n%10; n/=10;}
    return m==nn;
}

int main(){
    ll A, p, q;
    cin>>p>>q;
    vector <bool> a(N, 0);
    ll splay=0, palindrom=0;
for (ll i=2; i<N; i++)
    if (a[i]==0)
        for (ll j=i*i; j<N; j+=i)
            a[j]=1;
a[1]=1;

int ans=-1;
for (int i=1; i<N; i++){
    if (!a[i])
        splay++;
    
    if (check(i))
        palindrom++;

    if (q*splay<=p*palindrom)
        ans=i;
}
if (ans!=-1) cout<<ans;
else cout<<"Palindromic tree is better than splay tree";
}