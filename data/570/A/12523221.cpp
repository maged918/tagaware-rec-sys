//Language: GNU C++


#include<stdio.h>
#include<string.h>
int a[110];
int main(){
    int n,m,ans=0,tmp=-1,x;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    int l;
    for(int i=1;i<=m;i++){
            int t=-1;
        for(int j=1;j<=n;j++){
            scanf("%d",&x);
            if(x>t){
                t=x;
                l=j;
            }
        }
        a[l]++;
    }
    for(int i=1;i<=100;i++){
        if(a[i]>tmp){
            tmp=a[i];
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
