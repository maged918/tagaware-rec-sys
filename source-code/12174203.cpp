//Language: GNU C++11


#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[200000];
int main()
{
	int n,m,t,sum;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
	    }
	    sort(a,a+n);
	   if(a[0]==1)
	    printf("-1\n");
	    else
	    printf("1");
	    
		
	}
 } 
