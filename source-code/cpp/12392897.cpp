//Language: GNU C++


#include <cassert>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
#define err(...) fprintf(stderr,__VA_ARGS__)

int N;
int a[100000];

int main() {
	scanf("%d",&N);
	for (int i=0; i<N; i++) scanf("%d",a+i);
	for (int i=0; i<N; i++) {
		int small = 2000000000;
		int large = 0;
		if (i > 0) small = a[i]-a[i-1];
		if (i < N-1) small = min(small, a[i+1]-a[i]);
		large = max(a[i]-a[0],a[N-1]-a[i]);
		printf("%d %d\n",small,large);
	}
}
