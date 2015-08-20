//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1008;
int main()
{
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	int x=m-1;
	//if(m-2>0)	x--;
	int y=n-m;
	//if(m+2<=n)	y--;
	if(x>=y)	printf("%d\n",m-1);
	else
		printf("%d\n",m+1);
	return 0;
 } 