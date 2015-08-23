//Language: GNU C++


#include <stdio.h>
#include <algorithm>
using namespace std;
const long long MOD = 1000000007;
pair<int,int> p[2005];
long long dpa[2005],f[200005];
int h,w,n;

long long powmod(long long x,long long y){
	long long res=1;
	x%=MOD;
	while(y!=0){
		if(y&1)res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}

long long go(long long x,long long y){
	return f[x+y]*powmod(f[x]*f[y],MOD-2)%MOD;
}

int main(){
	scanf("%d %d %d",&h,&w,&n);
	f[0]=1;
	for(int i=1;i<=200000;i++)f[i]=f[i-1]*i%MOD;
	for(int i=0;i<n;i++)scanf("%d %d",&p[i].first,&p[i].second);
	p[n]=make_pair(h,w);
	p[n+1]=make_pair(1,1);
	n+=2;
	sort(p,p+n);
	dpa[0]=1;
	for(int i=1;i<n;i++){
		dpa[i]=go(p[i].first-1,p[i].second-1);
		for(int j=1;j<i;j++)if(p[j].first<=p[i].first && p[j].second<=p[i].second){
			dpa[i]=(dpa[i]-go(p[i].first-p[j].first,p[i].second-p[j].second)*dpa[j])%MOD;
		}
	}
	printf("%I64d\n",(dpa[n-1]+MOD)%MOD);
	return 0;
}