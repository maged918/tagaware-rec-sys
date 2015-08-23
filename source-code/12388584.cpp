//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200002;
const long long MAX = 1e15;

map<long long, long long> before, after;
int N, K, arr[MAXN];

bool overflow(long long a, long long b)
{
	if(MAX / b < a )
		return true;
	return false;
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]), after[arr[i]]++;
	
	long long ret = 0;
	
	for(int i=0; i<N; i++)
	{
		after[arr[i]]--;
		long long cur = arr[i];
		if(cur%K == 0 && before.count(cur/K) && after.count(cur*K))
			ret += before[cur / K] * after[cur * K];
		before[arr[i]]++;
	}
	printf("%I64d\n", ret);
}
