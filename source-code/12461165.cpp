//Language: GNU C++11



#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
	double T,S,q;
	
	cin>>T>>S>>q;
	
	int ans = 0;
	while (S<T)
	{
		ans++;
		double t = q * S;			// Vt + x0 = V't + x0'
		double s = t * (q-1)/q;		// x = Vt
		S += s;
	}
	
	cout<<ans;
	return 0;
}