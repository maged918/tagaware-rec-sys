//Language: GNU C++


#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int a[6];
const double pi=M_PI;
const double eps=1e-4;
const double st[4]={pi/3,pi/3*2,pi+pi/3,pi+pi/3*2};
const double xs=sqrt(3)/4;
bool bb;
void update(double s){
	bb=true;
	printf("%d\n",(int)round(s/xs));
	return;
}
void dfs(int dep,double x,double y,double w,double s){
//	printf("%lf %lf %lf %lf %d\n",x,y,s,w,dep);
	if(bb)return;
	if(dep==6){
		if(abs(x)<=eps&&abs(y)<=eps)update(s);
		return;
	}
	for(int i=0;i<4;i++){
		double ww=w+st[i];
		double xx=x+cos(ww)*a[dep];
		double yy=y+sin(ww)*a[dep];
		double ss=s;
//		if(dep!=5)
		ss+=(x*yy-y*xx)/2;
		dfs(dep+1,xx,yy,ww,ss);
	}
}
int main(){
	for(int i=0;i<6;i++)scanf("%d",&a[i]);
	dfs(1,a[0],0,0,0);
//	system("pause");
	return 0;
}
