//Language: GNU C++11


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int T,s,q;
	scanf("%d%d%d",&T,&s,&q);
	int res=1;
	while (s*q<T)
	{
		res+=1;
		s=s*q;
	}
	printf("%d",res);
}
