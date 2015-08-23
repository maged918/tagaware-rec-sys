//Language: GNU C++11


#include <bits/stdc++.h>

#define maxn 200010
#define fi first
#define se second

using namespace std;

typedef long long int lint;

typedef pair < lint , lint > i2;

typedef pair < i2 , int > i3;

typedef pair < i2 , i2 > i4;

lint n,ar[maxn],k,x,er[maxn],asd[maxn],used[maxn];

map<i2,lint> mp;

lint m;

int main()
{
	scanf("%lld %lld",&n,&k);
	
	for(lint i=1;i<=n;i++)
		scanf("%lld",&ar[i]);
	
	for(lint i=n;i>=1;i--)
	{
		mp[i2(ar[i],3)]+=mp[i2(ar[i]*k,2)];
		mp[i2(ar[i],2)]+=mp[i2(ar[i]*k,1)];
		mp[i2(ar[i],1)]++;
	}
	
	for(lint i=1;i<=n;i++)
	{
		m+=mp[i2(ar[i],3)];
		
		mp[i2(ar[i],3)]=0;
	}
	
	printf("%lld\n",m);
	
	return 0;
}
