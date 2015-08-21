//Language: GNU C++


#include <iostream>
#include <string>
#include <vector>


using namespace std;

typedef long long ll;


const ll MOD = 1000000007;
const int LIM = 4001;
ll C[LIM][LIM];
ll B[LIM];



int main()
{
	int m;
	cin >> m;

	for (int n = 0; n< LIM; ++n)
	{
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k<n; ++k) 
		{
			C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
		}
	}

	B[0] = 1;
	for (int n = 0; n + 1 < m; ++n) 
	{
		for (int k = 0; k <= n; ++k) 
		{
			B[n + 1] = (B[n + 1] + (C[n][k] * B[k]) % MOD) % MOD;
		}
	}

	ll r = 0;
	for (int k = 0; k < m; ++k) 
	{
		r = (r + (C[m][k] * B[k]) % MOD) % MOD;
	}
	cout << r << endl;

	return 0;
}