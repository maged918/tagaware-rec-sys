//Language: GNU C++11


#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#define X first
#define Y second
#define mp make_pair
using namespace std;
const int N = 555;
const int mod = (int)1e9 + 7;
int f[2][N][N];
char g[N][N];
const pair<int,int>d1[2] = {mp(0,1),mp(1,0)};
const pair<int,int>d2[2] = {mp(1,0),mp(0,1)};
char read(){
	char x = getchar();
	while (!isalpha(x)) x = getchar();
	return x;
}
void DP(int n,int m){
	if (n == 1 && m == 1){
		puts("1");return;
	}
	memset(f[0],0,sizeof f[0]);
	f[0][0][0] = 1;
	int now = 0,nxt;
	for (int i = 0;;i ++){
		if ((i + 2) * 2 > n + m - 1) break;
		nxt = now ^ 1;
		memset(f[nxt],0,sizeof f[nxt]);
		for (int j = 0;j <= i;j ++)
			for (int k = 0;k <= i;k ++){
				if (!f[now][j][k]) continue;
				int x = 1 + j,y = 1 + (i - j); // left
				int r = n - k,c = m - (i - k); // right
				for (int fir = 0;fir < 2;fir ++){
					int tx = x + d1[fir].X,ty = y + d1[fir].Y;
					if (tx == 0 || tx > n || ty == 0 || ty > m) continue;
					for (int sec = 0;sec < 2;sec ++){
						int tr = r - d2[sec].X,tc = c - d2[sec].Y;
						if (tr == 0 || tc == 0 || tr > n || tc > m) continue;
						if (g[tx][ty] == g[tr][tc]){
							(f[nxt][j + d1[fir].X][k + d2[sec].X] += f[now][j][k]) %= mod;
						}
					}
				}
			}
		now ^= 1;
		//printf("%d %d\n",i + 1,f[now][1][1]);
	}
	int step = (n + m - 1) / 2 - 1;
	if (step < 0) step = 0;
	int flag = (n + m - 1) & 1;
	int ans = 0; 
	for (int i = 0;i <= step;i ++)
		for (int j = 0;j <= step;j ++){
			int x = 1 + i,y = 1 + step - i;
			int r = n - j,c = m - (step - j);
			if (x == 0 || y == 0 || x > n || y > m) continue;
			if (r == 0 || c == 0 || r > n || c > m) continue;
			//printf("%d %d %d %d\n",x,y,r,c);
			if (!flag){
				if (y == c && x + 1 == r) ans = (ans + f[now][i][j]) % mod;
				if (x == r && y + 1 == c) ans = (ans + f[now][i][j]) % mod;
			}else{
				if (x + 2 == r && y == c) ans = (ans + f[now][i][j]) % mod;
				if (x + 1 == r && y + 1 == c) ans = (ans + 2 * f[now][i][j] % mod) % mod;
				if (x == r && y + 2 == c) ans = (ans + f[now][i][j]) % mod;
			}
		}
	printf("%d\n",ans);
}
int main(){
	//freopen("E.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= m;j ++) g[i][j] = read();
	if (g[1][1] != g[n][m]) puts("0"); else DP(n,m);
	return 0;
}
