//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<iomanip>
#define LL long long
#define PI acos(-1.0)
#define MOD 1000000007
#define eps 1e-6
using namespace std;
int sum[1000005];
int l[1000005],r[1000005];
int main(){
    int n;
    cin>>n;
    memset(sum,0,sizeof(sum));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    int a[100005]={0};
    int maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(sum[a[i]]==0)
            l[a[i]]=i,r[a[i]]=i;
        else
            r[a[i]]=i;
        sum[a[i]]++;
        maxn=max(maxn,sum[a[i]]);
    }
    int ans,temp=MOD;
    for(int i=1;i<=n;i++){
        if(sum[a[i]]==maxn){
            if(temp>r[a[i]]-l[a[i]]){
                ans=a[i];
                temp=r[a[i]]-l[a[i]];
            }
        }
    }
    cout<<l[ans]<<" "<<r[ans]<<endl;
    return 0;
}