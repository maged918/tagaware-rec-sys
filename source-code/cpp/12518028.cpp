//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,ans;
	scanf("%d %d",&n,&m);
	if(n-m>m-1)
	ans=m+1;
	else
	ans=m-1;
	if((m==1)&&(n==1))
	ans=1;

	
	printf("%d",ans);
	return 0;
}