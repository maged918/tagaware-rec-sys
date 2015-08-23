//Language: GNU C++


#include<iostream>
#include<cstdio>
using namespace std;
typedef struct point{
    double x,y;
}point;
point a[6];
int main(){
    double a1,a2,a3,a4,a5,a6,ans=0;
    scanf("%lf%lf%lf%lf%lf%lf",&a1,&a2,&a3,&a4,&a5,&a6);
    a[0].x=0;
    a[0].y=0;
    a[1].x=a6;
    a[1].y=0;
    a[2].x=a5/2;
    a[2].y=a5;
    a[3].x=-a4/2;
    a[3].y=a4;
    a[4].x=-a3;
    a[4].y=0;
    a[5].x=-a2/2;
    a[5].y=-a2;
    for(int i=1;i<6;i++){
        a[i].x+=a[i-1].x;
        a[i].y+=a[i-1].y;
    }
    for(int i=1;i<6;i++){
        ans+=(a[i].y*a[i-1].x-a[i-1].y*a[i].x);
    }
    printf("%d",(int)ans);
    return 0;
}
