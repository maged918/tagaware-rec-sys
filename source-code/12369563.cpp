//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define LL __int64
LL Min[maxn],Max[maxn],a[maxn];
int N;

int main(){
    //freopen("in.txt","r",stdin);
    while(cin>>N){
        for(int i=0;i<N;i++)
            scanf("%I64d",a+i);
        //for(int i=0;i<N;i++) cout<<a[i]<<" ";cout<<endl;
        Min[0]=a[1]-a[0];Max[N-1]=Max[0]=a[N-1]-a[0];
        Min[N-1]=a[N-1]-a[N-2];
        for(int i=1;i<N-1;i++){
            Min[i]=min(a[i]-a[i-1],a[i+1]-a[i]);
            Max[i]=max(a[N-1]-a[i],a[i]-a[0]);
        }
        for(int i=0;i<N;i++)
            printf("%I64d %I64d\n",Min[i],Max[i]);
    }
    return 0;
}
