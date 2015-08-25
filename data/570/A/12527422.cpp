//Language: GNU C++


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	long long int i,j,k,l,m,n,t,idx;

	cin >> n >> m;

	long long int arr[m+1][n+1];

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			cin >> arr[i][j];
	}
	long long int win[m+1],fre[n+1];

	for(i=1;i<=m;i++)
	{
		t=-1;

		for(j=1;j<=n;j++)
		{
			if(arr[i][j]>t)
			{
				idx=j;
				t=arr[i][j];
			}
		}
		win[i]=idx;
	}
	memset(fre,0,sizeof(fre));

	for(i=1;i<=m;i++)
		fre[win[i]]++;
	t=-1;

	for(i=1;i<=n;i++)
		if(t<fre[i])
		{
			t=fre[i];
			k=i;
		}

		cout << k << endl ;
}