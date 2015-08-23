//Language: GNU C++11


#include <bits/stdc++.h>

#define MAXN (1 << 20)

using namespace std;

int N;
int a[MAXN];

void read()
{
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
}

int dp[MAXN];
int can[MAXN];
bool have[MAXN];

void zero(int i)
{
	have[0] = false;
	have[a[i]] = false;

	int curr = a[i];
	int cnt = 0;

	while(curr < MAXN)
	{
		curr *= 2;
		cnt++;

		if(curr < MAXN)
			if(have[curr])
				have[curr] = false;    
	}
	
	curr = a[i];
	cnt = 0;
	
	while(curr > 0)
	{
		curr /= 2;
		cnt++;
		
		if(have[curr]) 
			have[curr] = false;

		int bak = curr;
		int bakCnt = cnt;
		
		if(curr == 0)
			continue;
		
		while(bak < MAXN)
		{
			bak *= 2;
			bakCnt++;
		
			if(bak >= MAXN)
				continue;
			
			if(have[bak])
				have[bak] = false;
		}
	}	
}

void solve()
{
	memset(dp, 0, sizeof(dp));
	memset(can, 0, sizeof(can));

	for(int i = 0; i < N; i++)
	{
		int curr = a[i];
		int cnt = 0;
	
		zero(i);

		can[curr]++;
		have[curr] = true;
		curr = a[i];
		cnt = 0;

		while(curr < MAXN)
		{
			curr *= 2;
			cnt++;

			if(curr < MAXN)
			{
				dp[curr] += cnt;
				if(!have[curr])
				{
					can[curr]++;
					have[curr] = true;											        
				}								    
			}
		}

		curr = a[i];
		cnt = 0;

		while(curr > 0)
		{
			curr /= 2;
			cnt++;

			dp[curr] += cnt;
			
			if(!have[curr]) 
			{	
				can[curr]++;
				have[curr] = true;
			}

			int bak = curr;
			int bakCnt = cnt;

			if(curr == 0)
				continue;

			while(bak < MAXN)
			{
				bak *= 2;
				bakCnt++;

				if(bak >= MAXN)
					continue;

				if(!have[bak])
				{
					have[bak] = true;
					can[bak]++;
					dp[bak] += bakCnt;
				}
			}
		}
	}
		

	int ans = MAXN * 100;
	for(int i = 0; i < MAXN; i++)
	{
		//printf("%d: %d %d\n", i, dp[i], cnt[i]);
		if(can[i] >= N)
			ans = min(ans, dp[i]);
	}

	printf("%d\n", ans);
}

int main()
{
	read();
	solve();
	return 0;
}