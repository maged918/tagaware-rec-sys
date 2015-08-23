//Language: GNU C++


#include <iostream>
using namespace std;
int main()
{
	int t, s, q, num = 0;
	cin >> t >> s >> q;
	
	while (s < t)
	{
		s *= q;
		num++;
	}
	cout << num << endl;
	return 0;




}