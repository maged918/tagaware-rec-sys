//Language: MS C++


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool f[2000000];

int main()
{
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	string s; int x;
	int cur = 0;
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> x;
		if (s == "+")
		{
			f[x] = 1;
			cur++;
			mx = max(mx, cur);
		}
		else
		{
			if (f[x] == 1)
			{
				f[x] = 0;
				cur--;
			}
			else
				mx++;
		}
	}
	cout << mx;
	return 0;
}