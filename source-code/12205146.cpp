//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	if(arr[0]==1)
		printf("-1");
	else
	{
		printf("1");
	}
	return 0;
}
