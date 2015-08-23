//Language: GNU C++11


#include<iostream>
using namespace std;
int main()
{
	// chi maskhare :/
	int n, ans = 1;
	cin >> n;
	while (n--)
	{
		int val;
		cin >> val;
		if (val == 1)
			ans = -1;
	}
	cout << ans << endl;
}