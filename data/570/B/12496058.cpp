//Language: GNU C++11


#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int m,n;
	while(scanf("%d %d",&m,&n)==2)
	{
		if(m==1) puts("1");
		else
		{
			if(n>m/2) printf("%d\n",n-1);
			else printf("%d\n",n+1);
		}
	}
	return 0;
}
