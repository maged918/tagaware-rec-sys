//Language: GNU C++


#include <stdio.h>
#include <map>
#include <iostream>

typedef long long Long;

int n = 0;
int k = 0;
Long k0 = 0;
Long k1 = 0;
Long k2 = 0;
const int N = 200000;
Long a[N + 100];

std::map<Long,int> bef;
std::map<Long,int> aft;

void get_ll(Long & r)
{
	Long flag = 1LL;
	r = 0LL;
	char c = 0;
	do
	{
		c = getchar();
	}
	while(c == ' ' || c == '\n' || c == '\t');
	
	if(c == '-')
	{
		flag = -1LL;
		c = getchar();
	} 
	
	do
	{
		r *= 10LL;
		r += (Long)(c - '0');
		c = getchar();
	}
	while(c >= '0' && c <= '9');
	
	r *= flag;
}

int main()
{
	//freopen("ex.in","r",stdin);
	//freopen("ex.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	
	k0 = 1LL;
	k1 = 1LL * k;
	k2 = 1LL * k1;
	
	for(int i = 0;i < n;i++)
	{
		get_ll(a[i]);
		aft[a[i]] ++;
	}
	
	Long res = 0LL;
	for(int i = 0;i < n;i++)
	{
		if(a[i] % k1 != 0)
		{
			bef[a[i]]++;
			aft[a[i]]--;
		}
		else
		{
			aft[a[i]]--;
			res += 1LL * bef[a[i] / k1] * aft[a[i] * k1];
			bef[a[i]]++;
		}
	}
	
	std::cout<<res<<std::endl;
	
	return 0;
}
