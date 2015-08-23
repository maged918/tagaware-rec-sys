//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,m,i,j,k,l;
	cin >> n >> m;
	if(n==1)
		printf("%lld\n",n);
	else
	{
//		if(n%2==0)
//		{
			if(m<=n/2)
				printf("%lld\n",m+1);
			else
				printf("%lld\n",m-1);
//		}
//		else
//		{
//			if(m<=((n/2)+1))
//				printf("%lld\n",m+1);
//			else
//				printf("%lld\n",m-1);
//		}
	}
	return 0;
}