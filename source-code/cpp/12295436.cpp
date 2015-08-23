//Language: GNU C++


#include <stdio.h>
int main()
{
	int a1,a2,a3,b1,b2,b3;
	scanf("%d%d",&a1,&b1);
	scanf("%d%d",&a2,&b2);
	scanf("%d%d",&a3,&b3);
	if (a2+a3 <= a1 && b1>=b2 && b1>=b3)
		printf("YES\n");
	else if (a2+a3 <= b1 && a1>=b2 && a1>=b3)
		printf("YES\n");
	else if (b2+b3 <= a1 && b1>=a2 && b1>=a3)
		printf("YES\n");
	else if (b2+b3 <= b1 && a1>=a2 && a1>=a3)
		printf("YES\n");
	else if (a2+b3 <= a1 && b1>=b2 && b1>=a3)
		printf("YES\n");
	else if (a2+b3 <= b1 && a1>=b2 && a1>=a3)
		printf("YES\n");
	else if (b2+a3 <= a1 && b1>=a2 && b1>=b3)
		printf("YES\n");
	else if (b2+a3 <= b1 && a1>=a2 && a1>=b3)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}