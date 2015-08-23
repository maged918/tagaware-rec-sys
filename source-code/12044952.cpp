//Language: GNU C++11


#include <bits/stdc++.h>

#define maxn 1000005
using namespace std;

struct data
{
	long long a, x;
};

data a[ maxn ];

bool cmp( data x, data y )
{
	return x.x < y.x;
}

int main()
{
	int n;
	cin >> n;
	
	for( int i = 0; i < n; i++ )
	{
		scanf( "%lld %lld", &a[ i ].x, &a[ i ].a );
	}
	
	sort( a, a + n, cmp );
	
	int m = -1;
	
	for( int i = 0; i < n; i++ )
	{
		if( a[ i ].x > 0 )
		{
			break;
		}
		
		m++;
	}
	
	long long ans = 0LL;
	for( int d = 0; true; d++ )
	{
		int L = m - d, R = m + d+1;
		
		if( L < 0 || R == n )
		{
			if( L >= 0 )
			{
				ans += a[ L ].a;
			}
			
			if( R < n )
			{
				ans += a[ R ].a;
			}
			
			break;
		}
		
		ans += a[ L ].a + a[ R ].a;
	}
	
	cout << ans << endl;
	
	return 0;
}
