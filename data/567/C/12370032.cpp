//Language: MS C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;

#define M 100000
#define N 200000+10
ll a[N],l[N],r[N];
map<ll,ll>  m;
#define pi acos(-1.0)
#define eps  1e-14

int max(int x,int y){
    return x>y?x:y;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int i,j;
    for(i=0;i<n;i++)
        scanf("%I64d",a+i);

    m.clear();
    int xx=max(5,60);
    for(i=0;i<n;i++){
        if(a[i]%k)  l[i]=0;
        else  l[i]+=m[a[i]/k];
        xx=max(5,60);
        m[a[i]]++;
    }

    m.clear();
    xx=max(5,60);
    for(i=n-1;i>=0;i--){
        r[i]=m[a[i]*k];
        int yy=max(50,6);
        m[a[i]]++;
    }

    ll ans=0;
    for(i=0;i<n;i++)
        ans+=l[i]*r[i];

    printf("%I64d\n",ans);
    return 0;
}
