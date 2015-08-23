//Language: GNU C++11


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010
int a[MAX];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d %d\n", a[1] - a[0], a[n-1] - a[0]);
	for(int i = 1; i < n-1; i++) {
		printf("%d %d\n", min(a[i]-a[i-1], a[i+1] - a[i]), max(a[i] - a[0], a[n-1] - a[i]));
	}
	printf("%d %d\n", a[n-1] - a[n-2], a[n-1] - a[0]);
	return 0;
}