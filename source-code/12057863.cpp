//Language: GNU C++11


#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int n, a, b;

short s[1000000][21];

short size[1000000];
short rem[1000000];

stack<short> t;

int minsize = 22;

int main()
{
	cin >> n;
	
	for (int i = 0; i < 1000000; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			s[i][j] = -1;
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		
		while (a > 0)
		{
			t.push(a%2);
			a/=2;
		}
		
		b = 0;
		
		while (!t.empty())
		{
			s[i][b++] = t.top();
			t.pop();
		}
		
		size[i] = b;
	
		if (b < minsize)
			minsize = b;
	}
	
	bool vannulla = false;
	bool vanegy = false;
	
	int u = minsize;
	
	for (int i = 0; i < minsize; ++i)
	{
		vanegy = false;
		vannulla = false;
		
		for (int j = 0; j < n; ++j)
		{
			if (s[j][i] == 1)
			{
				vanegy = true;
			}
			else if (s[j][i] == 0)
			{
				vannulla = true;
			}
		}
		
		if (vanegy && vannulla)
		{
			u = i;
			break;
		}
	}
	
	long long int res = 0;
	
	for (int i = 0; i < n; ++i)
	{
		vanegy = false;
		
		for (int j = u; j < size[i]; ++j)
		{
			if (s[i][j] == 1 && !vanegy)
			{
				res += size[i]-j;
				rem[i] = j-u;
				vanegy = true;
			}
		}
		
		if (!vanegy)
			rem[i] = size[i]-u;
	}
	
	long long int minsum = 10000000;
	int sum = 0;
	
	for (int i = 0; i <= 20; ++i)
	{
		sum = 0;
		
		for (int j = 0; j < n; ++j)
			sum += abs(rem[j]-i);
			
		if (sum < minsum)
			minsum = sum;
	}
	
	cout << res+minsum << endl;
}

