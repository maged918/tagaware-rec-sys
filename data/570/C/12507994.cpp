//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char *s = (char *)malloc((n+2)*sizeof(char));
	s[0] = 'a';
	scanf("%s", s+1);
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (s[i] == '.' && s[i+1] == '.') ans++;
	for (int i = 0; i < m; i++) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		int j = 0, k = 0;
		if (s[x-1] == '.') j++;
		if (s[x+1] == '.') j++;
		if (s[x] != '.') k++; else k--;
		if (c == '.') k++; else k--;
		k = k/2;
		ans += j*k;
		printf("%d\n", ans);
		s[x] = c;
	}
	free(s);
	return 0;
}