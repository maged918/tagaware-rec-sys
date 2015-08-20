//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
int x,y,a,b,c,d;
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	scanf("%d %d",&x,&y);
	scanf("%d %d",&a,&b);
	scanf("%d %d",&c,&d);
	if(a*b+c*d>x*y){
		printf("NO\n");
	}else{
		int flag=true;
		if(a<=x&&b<=y){
			if(!(c+a>x&&d+b>y)&&c<=x&&d<=y)flag=false;
			if(!(d+a>x&&c+b>y)&&d<=x&&c<=y)flag=false;
		}
		if(a<=y&&b<=x){
			if(!(c+b>x&&a+d>y)&&c<=x&&d<=y)flag=false;
			if(!(d+b>x&&a+c>y)&&d<=x&&c<=y)flag=false;
		}
		if(flag){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}