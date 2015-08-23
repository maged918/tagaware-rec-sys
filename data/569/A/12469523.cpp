//Language: GNU C++


/* In The Name Of Allah */
#include <bits/stdc++.h>

using namespace  std; 

int main()
{
	int s , t , q , cnt = 0 ;
	
	cin >> t >> s >> q ;

	while(s < t)
	{
		s *= q ;
		cnt++ ;
	}

	cout << cnt << endl;
	

	return 0 ;
}