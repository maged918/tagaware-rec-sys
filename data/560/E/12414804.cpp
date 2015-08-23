//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#define LL long long int
#define MAXN 2050
#define MAXM 200050
#define mod 1000000007
using namespace std;

int h ,w ,n ;
LL dp[MAXN] ,ji[MAXM] ,ni[MAXM] ;

struct node
{
	int x ,y ;
	bool operator < (const node &a) const
	{
		return x+y<a.x+a.y;
	}
}point[MAXN] ;

LL power(LL a,LL pos)
{
	LL ans=1;
	while(pos>0)
	{
		if(pos&1)
			ans=ans*a%mod;
		a=a*a%mod;
		pos>>=1;
	}
	return ans;
}

void init()
{
	ji[0]=ni[0]=ji[1]=ni[1]=1;
	for(int i=2;i<=200000;++i)
	{
		ji[i]=ji[i-1]*i%mod;
		ni[i]=power(ji[i],mod-2);
	}
}

LL C(int a,int b)
{
	return ji[a]*ni[b]%mod*ni[a-b]%mod;
}

int main()
{
	init();
	while(~scanf("%d%d%d",&h,&w,&n))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&point[i].x,&point[i].y);
			--point[i].x ,--point[i].y;
		}
		point[n].x=h-1 ,point[n].y=w-1 ;
		sort(point,point+n+1);
		int x=point[0].x ,y=point[0].y ,u ,v ;
		dp[0]=C(x+y,x);
		for(int i=1;i<=n;++i)
		{
			x=point[i].x ,y=point[i].y ;
			dp[i]=C(x+y,x);
			for(int j=0;j<i;++j)
			{
				u=point[j].x ,v=point[j].y ;
				if(v>y||u>x)continue;
				dp[i]=(dp[i]-dp[j]*C(x+y-u-v,x-u)%mod)%mod;
				if(dp[i]<0)dp[i]+=mod;
			}
		}
		printf("%I64d\n",dp[n]);
	}
	return 0;
}
	  	 			  	 	 	 		 		  			  			