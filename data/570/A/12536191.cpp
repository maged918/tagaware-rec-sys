//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
	
	long long n,m,maxi=-1,maxv=-1,a,v[101]={0};
	scanf("%lld %lld",&n,&m);
	
	for(int j=1;j<=m;j++)	
	{
		maxv=-1;
		maxi=1;
		for(int i=1;i<=n;i++)
		{	
			scanf("%lld",&a);
			if(a>maxv)
			{
				maxv=a;
				maxi=i;
			}
		}
		v[maxi]++;
	}
		
		maxi=1;
		for(int i=1;i<=n;i++)
		{
			if(v[i]>v[maxi])
			maxi=i;
		}
		
		printf("%lld\n",maxi);

	return 0;
}