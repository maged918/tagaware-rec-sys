//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct fuck
{
	int a,b;
}s[105],p[105],q[105];

bool cmp(fuck x , fuck y)
{
	return x.a < y.a;
}

int main()
{
	int n,sum;
	while(cin >> n)
	{

		sum = 0;
		int ans1 = 0,ans2 = 0;
		for(int i = 0;i < n;i++)
		{
			cin >> s[i].a >> s[i].b;
			if(s[i].a > 0) p[ans1].a = s[i].a,p[ans1].b = s[i].b,ans1++;
			if(s[i].a < 0) q[ans2].a = s[i].a,q[ans2].b = s[i].b,ans2++;
		}
		sort(p,p+ans1,cmp);
		sort(q,q+ans2,cmp);
		if(ans1 == 0 && ans2 != 0) cout << q[ans2-1].b << endl;
		else if(ans2 == 0 && ans1 != 0) cout << p[0].b << endl;
		else
		{
			if(ans1 > ans2)
			{
				for(int i = 0;i < ans2+1;i++)
					sum += p[i].b;
				for(int i = 0;i < ans2;i++)
					sum += q[i].b;
			}
			else if(ans1 < ans2)
			{
				for(int i = 0;i < ans1;i++)
					sum += p[i].b;
				for(int i = ans2;i >= ans2 - ans1 - 1;i--)
					sum += q[i].b;
			}
			else
			{
				for(int i = 0;i < ans1;i++)
					sum += q[i].b+p[i].b;
			}
			cout << sum << endl;
		}
	}
	return 0;
}
