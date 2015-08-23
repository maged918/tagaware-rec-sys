//Language: GNU C++11


#include<stdio.h>
#include<string.h>
#include<stack>
#include<string>
#include<math.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define LL __int64
#define inf 1999999999
#define N 110
#define min(a,b)(a<b?a:b)
#define max(a,b)(a>b?a:b)
int main()
{
	int n,m;
	int ans;
	scanf("%d%d",&n,&m);
	if(n==1) printf("1\n");
	else if(n-m<=m-1)
	{
		printf("%d\n",m-1);
	}
	else printf("%d\n",m+1);
	return 0;
}