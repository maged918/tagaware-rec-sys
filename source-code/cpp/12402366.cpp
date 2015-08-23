//Language: GNU C++11


#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include<ostream>
using namespace std;
#define pb(x) push_back(x)
#define make(x,y) make_pair(x,y)
typedef __int64 ll;
typedef pair<int, int> pii;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#pragma comment(linker, "/STACK:1024000000,1024000000")

const int N=200000+5;
const int M=5000+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int n,k;
int a[N];

map<int,int> mp;
//int mp1[N];
//vector<int> ve[N];
//vector<int> edge[N];
int num[N]={0};
ll tmp[N]={0};
int main() {
    //printf("%d\n",inf);
    scanf("%d%d",&n,&k);
    int t=0;
    for(int i=0;i<n;i++) {
        scanf("%d",a+i);
        if(mp[a[i]]==0) mp[a[i]]=++t;
        num[mp[a[i]]]++;
        //ve[mp[a[i]]].pb(i);
    }
    if(k==1) {
      ll ans=0;
        for(int i=1;i<=t;i++) {
            int num1=num[i];
            if(num1>=3) ans+=1ll*num1*(num1-1)*(num1-2)/6;
        }
        printf("%I64d\n",ans);
        return 0;
    }
    memset(num,0,sizeof(num));
    //for(int i=0;i<n;i++) ve[mp[a[i]]].pb(i);
    ll ans=0;
    for(int i=n-1;i>=0;i--) {
        if(1ll*a[i]*k<inf  && 1ll * a[i]*k>-inf && mp[a[i]*k]!=0) ans+=tmp[mp[a[i]*k]];
        if(1ll*a[i]*k<inf && 1ll * a[i]*k>-inf && mp[a[i]*k]!=0) tmp[mp[a[i]]]+=num[mp[a[i]*k]];
        num[mp[a[i]]]++;
    }

    printf("%I64d\n",ans);
    return 0;
}
