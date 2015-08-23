//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
int prime = 0, hui = 0;
int num = 0;
int p, q;
inline int get_prime(int x)
{
	if (x == 0 || x == 1)
		return 0;
	if (x == 2)
		return 1;
	for (int j = 2; j <= sqrt(x) + 1; ++j)
		if (x % j == 0)
			return 0;
	return 1;
}
inline int get_hui(int x)
{
	int q1[50];
	int y = x, f = 0;
	while (y > 0)
	{
		++f;
		q1[f] = y % 10;
		y /= 10;
	}
	bool oo = 0;
	for (int i = 1; i <= (f + 1) / 2; ++i)
		if (q1[i] != q1[f - i + 1])
			return 0;
	return 1;
}
int main()
{
	scanf("%d%d", &p, &q);
	int i = 1;
	while (i <= 2000000)
	{
		prime += get_prime(i);
		hui += get_hui(i);
		//printf("%d %d %d\n", i, prime, hui);
		if (prime <= hui * p / q)
			num = i;
		++i;
	}
	if (num < 2000000)
		printf("%d\n", num);
	else
		printf("Palindromic tree is better than splay tree\n");
	return 0;
}
