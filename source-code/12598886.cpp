//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int Maxn=1e9+7;

int n,m,k,i,j,Max;

long long Mod[200001],f[2001],c[2],Mul_inv[200001];

struct coor
{
	int x,y;
	bool operator < (const coor& b) const {
		return x<b.x || (x==b.x && y<b.y);
	}
} a[2001];

bool cmp(int i,int j)
{
	return a[i]<a[j];
}

long long gcd_extended(long long x,long long y)
{
	long long q=x/y;
	long long r=x % y;
	long long t=(c[0]-c[1]*q) % Maxn;
	if (r==1) return t;
	c[0]=c[1];
	c[1]=t;
	return gcd_extended(y,r);
}

long long combination(int k1,int k2)
{
	int n=k1+k2;
	return (Mul_inv[k2] * Mul_inv[k1] % Maxn) * Mod[n] % Maxn;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (i=0;i<k;i++) scanf("%d %d",&a[i].x,&a[i].y);
	sort(a,a+k);
	a[k].x=n;
	a[k].y=m;
	Mod[0]=1;
	Mul_inv[0]=1;
	Max=m+n-2;
	for (i=1;i<=Max;i++)
	{
		Mod[i]=Mod[i-1]*i % Maxn;
		c[0]=1;
		c[1]=0;
		Mul_inv[i]=gcd_extended(Mod[i],Maxn);
	}
	k++;
	for (i=0;i<k;i++)
	{
		f[i]=combination(a[i].x-1,a[i].y-1);
		for (j=0;j<i;j++)
		if ((a[i].x>=a[j].x) and (a[i].y>=a[j].y)) f[i]=(f[i]-combination(a[i].x-a[j].x,a[i].y-a[j].y)*f[j]) % Maxn;
		if (f[i]<0) f[i]+=Maxn;
	}
//	if (f[k-1]<0) f[k-1]+=Maxn;
	printf("%d\n",f[k-1]);
	return 0;
}
