//Language: MS C++


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100005
#define inf 0x3f3f3f3f
int x[maxn];
int main()
{
    int n;
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        printf("%d %d\n",x[2]-x[1],x[n]-x[1]);
        for(int i=2;i<n;i++){
            printf("%d %d\n",min(x[i+1]-x[i],x[i]-x[i-1]),max(x[n]-x[i],x[i]-x[1]));
        }
        printf("%d %d\n",x[n]-x[n-1],x[n]-x[1]);
    }
}
