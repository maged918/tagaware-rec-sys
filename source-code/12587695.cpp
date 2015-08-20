//Language: GNU C++


#include <iostream>

using namespace std;

int main()
{
	int n,m,a;
	cin >> n >> m;
	
	if (n == 1) { cout << 1 << endl; return 0;}
	
	if (m<=n/2) a = m+1;
	else a = m-1;
	
	cout << a << endl;
	
	return 0;
}
