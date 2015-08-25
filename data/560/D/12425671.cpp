//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
#define N 200010
char a[N], b[N];
int isok(char a[], char b[], int len)
{
	for (int i = 0; i < len; i++)
		if (a[i] != b[i])
			return 0;
	return 1;
}
int cmp(char a[], char b[], int len)
{
	if (isok(a, b, len))
		return 1;
	if (len % 2 == 0)
	{
	return ((cmp(a+len/2, b, len/2) && cmp(a, b+len/2, len/2)) ||
			(cmp(a, b, len/2) && cmp(a+len/2, b+len/2, len/2)));
	}
	return 0;
}
int main()
{
    //freopen("H:\\in.txt","r",stdin);
    //freopen("H:\\out.txt","w",stdout);
	scanf("%s %s", a, b);
	int len = strlen(a);
	puts(cmp(a, b, len) ? "YES" : "NO");
    return 0;
}
