//Language: GNU C++


#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

int n;
int m;
int ans;
int main ()
{
	scanf("%d%d",&n,&m);
	if(m<n&&m>1)
	{
		int a=n-m;
		int b=m-1;
		if(a>b)ans=m+1;
		else ans=m-1;
	}
	if(m==n)ans=n-1;
	if(m==1)ans=2;
	if(n==1)ans=1;
	printf("%d",ans);
}
