//Language: GNU C++


#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a1,b1,a2,b2,a3,b3;
    scanf("%d%d",&a1,&b1);
    scanf("%d%d",&a2,&b2);
    scanf("%d%d",&a3,&b3);
    if(a1<b1) swap(a1,b1);
    if(a2<b2) swap(a2,b2);
    if(a3<b3) swap(a3,b3);
    if(a2>a3){
        if(a2>a1) printf("NO\n");
           else{
            if(b2>b1) printf("NO\n");
            else{
                int tmp=b1-b2;
                if(tmp>=b3) printf("YES\n");
                else {
                       if(max(a3,b3)>a1) printf("NO\n");
                       else {
                        if(a1-a2>=min(a3,b3)) printf("YES\n");
                        else{swap(a1,b1); 
                            if(b3<=b1-b2&&a2<=a1) printf("YES\n");
                            else printf("NO\n");
                        }
                    }
                }
               }
        } 
       }
       else{
        if(a3>a1)  printf("NO\n");
        else{
            if(b3>b1)  printf("NO\n");
            else {
               int ans=b1-b3;
               if(ans>=b2) printf("YES\n");
               else {
                       if(max(a2,b2)>a1) printf("NO\n");
                       else {
                        if(a1-a3>=min(a2,b2)) printf("YES\n");
                        else {
                            swap(a1,b1); 
                            if(b2<=b1-b3&&a3<=a1) printf("YES\n");
                            else printf("NO\n");
                        }
                    }
                }
            }
           }
    }
    return 0;
}