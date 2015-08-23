//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n,m,i,j;

int main()
{
	scanf("%d %d",&n,&m);
	if (n==1) printf("1\n");
	else
	{
		if (n-m==m-1) printf("%d\n",m-1);
		else
		{
			if (n-m>m-1) printf("%d\n",m+1);
			else printf("%d\n",m-1);
			
		}
	}
	
	
	return 0;
}
