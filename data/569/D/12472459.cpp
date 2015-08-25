//Language: GNU C++


#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>
#include<memory.h>
#include<assert.h>
#include<numeric>
#include<limits.h>
using namespace std;
const int md=1e9+7;
int n;
int c[4005][4005],cnt[4005],cnt2[4005];
int main()
{
	scanf("%d",&n);
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%md;
	}
	cnt[0]=1;
	for(int i=0;i<n;i++)for(int j=1;j+i<=n;j++)cnt[i+j]=(cnt[i+j]+(long long)cnt[i]*c[n-i-1][j-1])%md;
	cnt2[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j+i<=n;j++)cnt2[i+j]=(cnt2[i+j]+(long long)cnt2[i]*c[n-i-1][j-1])%md;
		cnt2[i+1]=(cnt2[i+1]+cnt2[i])%md;
	}
	int ans=(cnt2[n]-cnt[n]+md)%md;
	cout<<ans<<endl;
	return 0;
}
