//Language: GNU C++


#include <stdio.h>
#define maxn 110

int n,m;

int main(void){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n == 1){
	   printf("1");
	   return 0;
	}
	int mid = (n+1)/2;
	if (m == mid && n%2 == 1) printf("%d",m-1);
	else if (m <= mid) printf("%d",m+1);
	else printf("%d",m-1);
	return 0;
}
