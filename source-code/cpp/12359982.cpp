//Language: GNU C++


#define maxN long(1e6+100)
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
long n,i,res,tmp,q[maxN][3],f[maxN];
string c;
int main()
{
	//freopen("B.inp","r",stdin);
	scanf("%ld",&n);
	for (i=1; i<=n; ++i)
	{
		cin>>c;
		if (c[0]=='-') q[i][1]=1; else q[i][1]=0;
		scanf("%ld",&q[i][2]);
		if (c=="-" && f[q[i][2]]==0)
		{
			tmp++;
			res=max(res,tmp);
		} else f[q[i][2]]=1;
	}
	
	for (i=1; i<=n; ++i)
	{
		if (q[i][1]==1)
		{
			tmp--;
			f[q[i][2]]=0;
		}
		else 
		{
			tmp++;
			f[q[i][2]]=1;
		}
		res=max(res,tmp);
	}
	printf("%ld",res);
	return 0;
}
