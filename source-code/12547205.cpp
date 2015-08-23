//Language: GNU C++11


#include <cstdio>
using namespace std;

int main()
{
	int t,s,q;
	scanf("%d%d%d",&t,&s,&q);
	int ans=0;
	while(s<t)
	{
		ans++;
		s*=q;
	}
	printf("%d\n",ans);
	return 0;
}