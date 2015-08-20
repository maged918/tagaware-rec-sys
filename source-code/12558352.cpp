//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <cstring>
#include "string.h"
#define sf(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x,&y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pb(x) push_back(x)
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vec;

#define MAX 1200000
int examples[4007][4007], N, v = 1e9 + 7, i, j;
/*int p, q;
int prime[MAX + 1];
int pal[MAX + 1];


void calculate_primes()
{
	int i, j;
	prime[1] = 1;
	for (i = 2; i <= sqrt(MAX); i++)
		if (prime[i] == 0)
			for (j = i*i; j <= MAX; j += i)
				prime[j] = 1;
	for (i = 1; i <= MAX; i++)
		prime[i] = 1 + prime[i - 1] - prime[i];
}

int hw(int num)
{
	int t = num, x = 0;
	while (num)
	{
		x = x * 10 + num % 10;
		num /= 10;
	}
	return t == x;
}

void calculate_palindromes()
{
	for (int i = 1; i <= MAX; i++)
	{
		pal[i] = pal[i - 1] + hw(i);
	}
}*/

int main()
{
	sf(N);
	for (i = 2, examples[1][1] = 1; i < N + 2; i++) {
		examples[i][1] = examples[i - 1][i - 1];
		for (j = 2; j <= i; j++)
			examples[i][j] = (examples[i][j - 1] + examples[i - 1][j - 1]) % v;
	}
	printf("%d\n", examples[N + 1][N]);
	//system("PAUSE");
	return 0;
}