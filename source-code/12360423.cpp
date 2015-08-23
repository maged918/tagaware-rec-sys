//Language: MS C++


//#include <fstream>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100005], k;
__int64 q, p;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << abs(a[1] - a[0]) << ' ' << abs(a[n - 1] - a[0]) << endl;

	for (int i = 1; i < n - 1; i++)
	{
		q = abs(a[i - 1] - a[i]);
		p = abs(a[i + 1] - a[i]);
		cout << min(q, p) << ' ';
		q = abs(a[n - 1] - a[i]);
		p = abs(a[0] - a[i]);
		cout << max(q, p) << endl;
	}
	cout << abs(a[n - 2] - a[n - 1]) << ' ' << abs(a[0] - a[n - 1]) << endl;
	//system("pause");
	return 0;
}