//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; ++i)

const int MAXN = 300500;
string s;
int n, m;      
int cur;

int main()
{                            
	cin >> n >> m;
	cin >> s;
	forn(i, n)
	{
		if (s[i] != '.')
			s[i] = 'a';
	}

	forn(i, n - 1)
	{
		cur += (int)(s[i] == '.' && s[i + 1] == '.');

	}
                               
	forn(i, m)
	{
		int ind;
		char c;
		cin >> ind >> c;
		if (c != '.')
			c = 'a';
		ind--;                  

		if (s[ind] != c)
		{
			if (s[ind] != '.')
			{
				if (ind != 0 && s[ind - 1] == '.')
					cur++;
				
				if (ind != n - 1 && s[ind + 1] == '.')
					cur++;


			}
			else
			{
			        if (ind != 0 && s[ind - 1] == '.')
					cur--;
				
				if (ind != n - 1 && s[ind + 1] == '.')
					cur--;

			}
			s[ind] = c;

		}

		cout << cur << '\n';

	}
	

	return 0;
}