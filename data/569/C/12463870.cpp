//Language: GNU C++11


#include<bits/stdc++.h>

using namespace std;

int p, q, pal, pr;
bool not_pr[1200005];

bool check(int x) {
	int y = x, z = 0, mod;
	while (y) {
		mod = y % 10;
		z = z * 10 + mod;
		y /= 10;
	}
	return z == x;
}

void seive() {
	not_pr[1] = not_pr[0] = 1;
	for (int i = 2; i * i <= 1200000; i++) {
		if (!not_pr[i])
			for (int j = i * i; j <= 1200000; j += i)
				not_pr[j] = 1;
	}
}

int main(int argc, char **argv) {
	scanf("%d%d", &p, &q);
	seive();
	int i, ans = -1;
	for (i = 1; i <= 1200000; ++i) {
		if (check(i))
			++pal;
		if (!not_pr[i])
			++pr;
		if (q * pr <= p * pal)
			ans = i;
	}
	if (ans != -1)
		printf("%d\n", ans);
	else
		puts("Palindromic tree is better than splay tree");
	return 0;
}
