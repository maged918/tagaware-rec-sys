//Language: GNU C++11


#include<vector>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#include<queue>
#include<cstdio>
#include<sstream>

using namespace std;
#define size 1200000
int rub[size] = { 0 };
int prim[size] = { 0 };
bool check(int i)
{

	stringstream s;
	s << i;
	string x = s.str();
	if (x[x.length() - 1] == '0')
		return false;
	

	string x2 = x;
	reverse(x.begin(), x.end());
	if (x2 == x)
		return true;
	else
		return false;
}


void markMultiples(vector<bool> & arr, int a, int n)
{
	int i = 2, num;
	while ((num = i*a) <= n)
	{
		arr[num - 1] = 1; // minus 1 because index starts from 0.
		++i;
	}
}

// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n)
{
	// There are no prime numbers smaller than 2
	if (n >= 2)
	{
		// Create an array of size n and initialize all elements as 0
		vector<bool> arr(n, 0);

		/* Following property is maintained in the below for loop
		arr[i] == 0 means i + 1 is prime
		arr[i] == 1 means i + 1 is not prime */
		for (int i = 1; i<n; ++i)
		{
			if (arr[i] == 0)
			{
				//(i+1) is prime, print it and mark its multiples
				//printf("%d ", i + 1);
				prim[i + 1] = 1;
				markMultiples(arr, i + 1, n);
			}
		}
	}
}




int main()
{
	double a, b;
	cin >> a >> b;

	for (int i = 1; i < size; i++)
	{
		if (check(i))
			rub[i] = 1;
		else
			rub[i] = 0;
	}


	SieveOfEratosthenes(size);
	for (int i = 1; i < size; i++)
	{
		rub[i] = rub[i] + rub[i - 1], prim[i] = prim[i] + prim[i - 1];

	}
	int n;
	for (int i = 1; i < size; i++)
	{

		if (a*rub[i] >= prim[i] * b)
			n = i;
	}
	cout << n << endl;

	//cout << prim[size - 1] / rub[size - 1];

	return 0;
}