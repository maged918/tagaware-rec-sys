//Language: GNU C++


#include <iostream>
//#include <fstream>
char s[300000];
using namespace std;
int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	int n, m;
	cin >> n >> m;
	int k = 0;
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		if (s[i] == '.')
		{
			k++;
		}
		else
		{
			if (k>1)
				f += k - 1;
			k = 0;
		}
	}
	if (k > 1)
		f += k - 1;
	s[n] = '\0';
	for (int t = 0; t < m; t++)
	{
		int x;
		char g;
		cin >> x >> g;
		if (g !='.')
		{
			if (s[x - 1] == '.' && s[x - 2] == '.' )
				f--;
			if (s[x - 1] == '.' && s[x] == '.')
				f--;
		}
		else
		if (g == '.')
		{
			if (s[x - 1] != '.'&&s[x - 2] == '.')
				f++;
			if (s[x - 1] != '.'&&s[x] == '.')
				f++;
		}
		s[x - 1] = g;
		cout << f << endl;
	}
}