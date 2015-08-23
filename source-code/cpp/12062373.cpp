//Language: MS C++


#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>


using namespace std;


uint32_t main()
{
	uint32_t n;
	cin >> n;

	vector< pair< int32_t, int32_t > > a( n );
	for( uint32_t i = 0; i < n; i++ )
	{
		cin >> a[i].first >> a[i].second;
	}
	sort( a.begin(), a.end(), []( const pair< int32_t, int32_t >& p1, const pair< int32_t, int32_t >& p2 )->bool{ return p1.first < p2.first; } );

	vector< pair< int32_t, int32_t > >::iterator f = upper_bound( a.begin(), a.end(), 0, []( int32_t v, const pair< int32_t, int32_t >& p )->bool
	{
		return p.first > v;
	} );

	int neg = distance( a.begin(), f );
	int pos = distance( f, a.end() );

	int answer = 0;
	if( neg <= pos )
	{
		for( int i = 0; i < min( 2 * neg + 1, (int)a.size() ); i++ )
		{
			answer += a[i].second;
		}
	}
	else
	{
		for( int i = max( (int)a.size() - 2 * pos - 1, 0 ); i < a.size(); i++ )
		{
			answer += a[i].second;
		}
	}

	cout << answer << endl;
	return EXIT_SUCCESS;
}