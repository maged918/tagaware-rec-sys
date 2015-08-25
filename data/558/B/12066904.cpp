//Language: GNU C++


#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct Num{
	int l,r,cnt;
	Num(int _l=0,int _r=0,int _cnt=0):l(_l),r(_r),cnt(_cnt){}
};
const int maxn=1000005;
Num a[maxn];
int n;
int temp;
int ans=0;
void check(int);
int main() {
	R(n);
	rep(i,1,n,1) {
		R(temp);
		a[temp].cnt++;
		if(!a[temp].l) a[temp].l=i;
		a[temp].r=i;
	}
	rep(i,1,maxn-2,1){
		check(i);	
	}
	Ps(a[ans].l);
	Ps(a[ans].r);
	puts("");
}

void check(int k) {
	if(a[k].cnt>a[ans].cnt)
		ans=k;
	else if(a[k].cnt==a[ans].cnt) {
		if(a[k].r-a[k].l<(a[ans].r-a[ans].l))
			ans=k;
	}
	return ;
}
