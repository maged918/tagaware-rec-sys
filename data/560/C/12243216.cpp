//Language: GNU C++


#include <stdio.h>

int main(){

    int a1,a2,a3,a4,a5,a6;
    while(scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6)!=EOF){
            int ans=(a1*a2+a3*a4+a5*a6)*2+(a2-a5)*(a2-a5);
            printf("%d\n",ans);
    }
}
