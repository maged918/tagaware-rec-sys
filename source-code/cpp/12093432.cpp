//Language: GNU C++11


#include<bits/stdc++.h>

#define ll long long int
#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b

using namespace std;

int main()
{	
	ll one = 1;
	ll left, right, l, r;
	ll n, q, level, ans;
	scanf("%I64d %I64d", &n, &q);
	left = one<<(n-1);
	right = one<<(n);
	right -= 1;

	vector< pair<ll,ll> >a;

	for(int i = 0; i < q; i++)
	{
		scanf("%I64d %I64d %I64d %I64d", &level, &l, &r, &ans);
		l = l*(one<<(n-level));
		//r = ((r+1)*(1<<(n-level))) - 1;
		r = r*(one<<(n-level));
		r += (one<<(n-level));
		r -= 1;

		if(ans)
		{
			left = max(left, l);
			right = min(right, r);
		}
		if(!ans)
		{
			a.push_back(make_pair(l, r));
		}
	}

	sort(a.begin(), a.end());
	int sz = a.size();

	for(int i = 0; i < sz; i++)
	{
		if((a[i].first<=left) && (a[i].second>=left))
		{
			left = a[i].second + 1;
		}
	}

	for(int i = sz - 1; i >= 0; i--)
	{
		if((a[i].first<=right) && (a[i].second>=right))
		{
			right = a[i].first - 1;
		}
	}

	if(left > right)
		printf("Game cheated!\n");
	else if((right-left) > 0)
		printf("Data not sufficient!\n");
	else
		printf("%I64d\n", left);

	return 0;
}