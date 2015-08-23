//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n==1 && m==1)
	{
		cout<<"1"<<"\n"; 
	}
	else
	{
		if(n-m>m-1)
		{
			cout<<m+1<<"\n";
		}
		else
		{
			cout<<m-1<<"\n";
		}
	}
	return 0;
}
