//Language: GNU C++


#include <cstdio>
#include <iostream>

using namespace std;

int n,m,cnt,a;
char dp[1000005],nul[100],aa;

int main() {
	scanf("%d %d",&n,&m);
	gets(dp);
	gets(dp);
	for (int i=0;i<n;i++) {
		if (dp[i] == '.' && dp[i+1] == '.') {
			cnt++;
		}
	}
	for (int i=0;i<m;i++) {
		scanf("%d %c",&a,&aa);
		a--;
		if (aa != '.') {
			if (dp[a] == '.') {
				dp[a] = 'a';
				if (dp[a+1] == '.') cnt--;
				if (dp[a-1] == '.') cnt--;
			}
		}else if (aa  == '.' && dp[a] != '.') {
			dp[a] = '.';
			if (dp[a+1] == '.') cnt++;
			if (dp[a-1] == '.') cnt++;
		}
		gets(nul);
		printf("%d\n",cnt);
	}
}