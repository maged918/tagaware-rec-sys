//Language: GNU C++11


#include <iostream>
#include <cmath>

typedef unsigned long long int I64;

using namespace std;

inline I64 solve(I64 a1,I64 a2,I64 a3,I64 a4,I64 a5,I64 a6)
{
	I64 x = a1+a2+a3;
	I64 y = pow(x,2) - pow(a1,2) - pow(a3,2) - pow(a5,2);
	return y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	I64 a1,a2,a3,a4,a5,a6;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	cout << solve(a1,a2,a3,a4,a5,a6) << endl;
	return 0;
}
