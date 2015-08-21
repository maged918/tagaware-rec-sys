//Language: GNU C++


#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a1,a2,a3,a4,a5,a6;
    while(~scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6)){
        int x1=a1+a2+a6;
        int sum=x1*x1-a2*a2-a4*a4-a6*a6;
        printf("%d\n",sum);
    }
}