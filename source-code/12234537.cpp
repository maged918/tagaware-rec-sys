//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a1,a2,a3,b1,b2,b3;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
		int d1,d2,d3;
		d1=min(n-a2-a3,b1);
		d1=max(a1,d1);
		d2=min(n-d1-a3,b2);
		d2=max(a2,d2);
		d3=n-d1-d2;
		printf("%d %d %d\n",d1,d2,d3);
	}
	return 0;
} 
