//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,x[100010],minn[100010],maxx[100010];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&x[i]);
	} 
	for (int i=1;i<=n;i++) {
		minn[i] = min(x[i]-x[i-1],x[i+1]-x[i]);
		if (i==1) minn[i] = x[i+1]-x[i];
		if (i==n) minn[i] = x[i]-x[i-1];
		maxx[i] = max(x[i]-x[1],x[n]-x[i]);
		if (i==1) maxx[i] = x[n]-x[i];
		if (i==n) maxx[i] = x[i]-x[1];
		printf("%d %d\n",minn[i],maxx[i]);
	}
	return 0;
}
