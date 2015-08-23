//Language: GNU C++11


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
int a[100005];
int x[100005],y[100005];
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++){
        x[i]=2000000000;
        y[i]=-2000000000;
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        if(i!=1){
            x[i]=min(x[i],a[i]-a[i-1]);
            y[i]=max(y[i],a[i]-a[1]);
        }
        if(i!=n){
            x[i]=min(x[i],a[i+1]-a[i]);
            y[i]=max(y[i],a[n]-a[i]);
        }
        printf("%d %d\n",x[i],y[i]);
    }
}