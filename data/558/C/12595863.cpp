//Language: GNU C++


#include <cstdio>
#define N_Max 123456

int n, cnt[N_Max], sum[N_Max];
int ans;

void init() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);

		int l = tmp, time = 0;
		while (l > 0) {
			cnt[l]++;
			sum[l] += time;

			if (l&1 && l != 1) {
				int tmpl = (l>>1)<<1, tmpt = time+2;
				while (tmpl < N_Max) {
					cnt[tmpl]++;
					sum[tmpl] += tmpt;

					tmpl <<= 1;
					tmpt++;
				}
			}

			time++;
			l >>= 1;
		}

		l = tmp, time = 0;
		while (l < N_Max) {
			cnt[l]++;
			sum[l] += time;

			time++;
			l <<= 1;
		}

		cnt[tmp]--;
	}
}

void solve() {
	ans = 0x7f7f7f7f;
	for (int i = 1; i < N_Max; i++)
		if (cnt[i] == n && ans > sum[i])
			ans = sum[i];

	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}
