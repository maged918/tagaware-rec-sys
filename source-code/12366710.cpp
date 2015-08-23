//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
#define ll long long 

int n;

ll  a[1111111];
ll  ta[1111111];
char A;
ll seat;
ll maxseat;
ll val;

int main ()
{
	cin>>n;
	memset(a,0,sizeof(a));
	memset(ta,0,sizeof(ta));
	seat=0;
	maxseat=0;
	for(int i=1;i<=n;i++)
	{
	
		scanf("%s%d",&A,&val);
		if (A=='+')
		{
		
			if( seat==maxseat)
			{
				maxseat++;
			}
			seat++;
			a[val]=1;
			ta[val]=1;
			

			
		}else
		{
			
			if(a[val]==1)
			{
			seat--;
			}
			a[val]=0;
			if(ta[val]==0)
			{
				maxseat++;
				ta[val]=1;
			}
		}
			
	}
	cout<<maxseat<<endl;

	return 0;
}