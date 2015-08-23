//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Prime=1000000007;

int n,i,j;

long long stirl[4001],sum[4001],combine[4001],m;

int main()
{
	stirl[1]=1;
	sum[0]=1;
	sum[1]=1;
	combine[1]=1;combine[0]=1;
	scanf("%d",&n);
	for (i=2;i<=n;i++)
		for (j=i;j>0;j--)
		{
			stirl[j]=(stirl[j]*j+stirl[j-1]) % Prime;
			sum[i]=(sum[i]+stirl[j]) % Prime;
			combine[j]=(combine[j]+combine[j-1]) % Prime;
		}
	m=0;
	for (i=0;i<n;i++) m=(m+sum[i]*combine[i]) % Prime;
	printf("%d\n",m);
	return 0;
}
