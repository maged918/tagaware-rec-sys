//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef long long int lld;

#define sz                           size()
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define mod 1000000007
#define __sync__		     std::ios::sync_with_stdio(false);
#define all(a)			     a.begin(),a.end()

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

void add(lld &a, lld b)
{
	a = (a+b)%mod;
}

lld dp[502][502][2];

string grid[502];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>grid[i];
	for(int l = (n+m-2)/2; l>=0 ; l--)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int a = i;
				int b = l - a;
				int c = n - 1 - j;
				int d = m - 1 - (l - j);
				if(a < 0 || a > n || b < 0 || b > m) continue;
				if(c < 0 || c > n || d < 0 || d > m) continue;
				if(grid[a][b] != grid[c][d]) continue;
				if(l==(n+m-2)/2)
				{
					if(a <= c && b <= d)
						dp[i][j][0] = 1;
					else dp[i][j][0] = 0;
					continue;
				}
				if(a+1 < n && c-1 >= 0) add(dp[i][j][0], dp[i+1][j+1][1]);
				if(a+1 < n && d-1 >= 0) add(dp[i][j][0], dp[i+1][j][1]);
				if(b+1 < m && c-1 >= 0) add(dp[i][j][0], dp[i][j+1][1]);
				if(b+1 < m && d-1 >= 0) add(dp[i][j][0], dp[i][j][1]);
			}
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				dp[i][j][1] = dp[i][j][0];
				dp[i][j][0] = 0;
			}
	}
	cout<<dp[0][0][1]<<"\n";
	return 0;
}      
