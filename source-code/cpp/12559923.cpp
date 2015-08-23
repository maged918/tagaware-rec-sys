//Language: GNU C++


#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	printf("%d",m <= n / 2 ? m + 1 :  (m - 1 > 0 ? m - 1 : m));
}