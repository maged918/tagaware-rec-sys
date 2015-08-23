//Language: GNU C++


#include<cstdio>
#include<iostream>

using namespace std;

int n, x, i;
int reachable[1000000];
int need_to_convert[1000000];

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &x);
		int trans_op_num = 0;
		while (x) {
			++reachable[x];
			need_to_convert[x] += trans_op_num;
			++trans_op_num;
			x >>= 1;
		}
	}
	for (i = 1e5; i > 1 && reachable[i] != n; --i);
	x = need_to_convert[i];
	while (true) {
		int y = reachable[i + i];
		if (n > y + y)
			break;
		i = i + i;
		x = x - y + n - y;
	}
	printf("%d\n", x);
	return 0;
}