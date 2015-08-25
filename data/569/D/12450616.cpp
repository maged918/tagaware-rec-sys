//Language: GNU C++11


#include <bits/stdc++.h>

#define icin(x) scanf("%d",&x)
#define LL long long
#define pb push_back
#define mod 1000000007
#define eps 1e-4
#define maxn 4000
using namespace std;

LL NcR[maxn+9][maxn+9];

void pre()
{
	for(int i=0;i<=maxn;i++)
	{
		NcR[i][0]=1;
		//NcR[0][i]=1;
	}
	for(int i=1;i<=maxn;i++)
	{
		for(int j=1;j<=maxn;j++)
		{
			NcR[i][j] = NcR[i-1][j] + NcR[i-1][j-1];
			if(NcR[i][j]>=mod)
				NcR[i][j]%=mod;
		}
	}

}

int main()
{
	int n;
	icin(n);
	pre();
	vector< LL > tn; 
	/*for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
			cout << NcR[i][j] << " ";
		cout << endl;
	}*/
	tn.pb(1);
	tn.pb(1);
	for(int i=2;i<=maxn;i++)
	{
		LL res=0;
		int k=i-1;
		for(int j=0;j<=k;j++)
		{
			res += tn[j]*NcR[k][j];
			if(res>=mod)
				res%=mod;
		}
		tn.pb(res);
	}
	LL ans=0;
	for(int i=n;i>0;i--)
	{
		ans += NcR[n][i]*tn[n-i];
		if(ans>=mod)
			ans%=mod;
	}

	cout << ans;
	return 0;
}
