//Language: GNU C++11


#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int pos,app;
	bool operator < (const node a) const
	{
		return pos < a.pos;
	}
}a[110],b[110];

int main()
{
	int n;
	scanf("%d",&n);
	int ans1 = 0,ans2 = 0;
	for (int i = 0;i < n; ++ i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x < 0)
		{
			x = -x;
			a[ans1].pos = x;
			a[ans1 ++].app = y;
		}
		else
		{
			b[ans2].pos = x;
			b[ans2 ++].app = y;
		}
	}
	sort (a,a + ans1);
	sort (b,b + ans2);
	int sum = 0;
	if (ans1 > ans2)
	{
		for (int i = 0;i <= ans2; ++ i)
			sum += a[i].app + b[i].app;
	}
	else if (ans2 > ans1)
	{
		for (int i = 0;i <= ans1; ++ i)
			sum += a[i].app + b[i].app;
	}
	else
	{
		for (int i = 0;i < ans2; ++ i)
			sum += a[i].app + b[i].app;
	}
	printf("%d\n",sum);
	return 0;
}
