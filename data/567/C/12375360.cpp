//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	long long n, d;
	bool operator < (const Node & A) const
	{
		if (n != A.n) return n < A.n;
		return d < A.d;
	}
};

map<Node, long long> m;

int main()
{
	Node A, B;
	long long n, k, a, ans = 0;
	scanf("%I64d%I64d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a);
		//if (a == 0) continue;
		A.n = a;
		if (a % k ==0)
		{
			B.n = a / k;
			B.d = 2;
			ans += m[B];
			A.d = 2; B.d = 1;
			m[A] += m[B];
		}
		A.d = 1; m[A]++;
	}
	printf("%I64d\n", ans);
	return 0;
}
