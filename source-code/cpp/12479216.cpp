//Language: GNU C++11


#include <bits/stdc++.h>

using namespace::std;

#define ll long long int

ll p,q,a;

ll mark[10000007];

ll sieve(ll n)
{
	ll i=2;

	ll count=0;
	ll j;
	mark[1]=1;

	for(i=2;i<n;i++)
	{
		mark[i]=0;
	}

	for(i=2;i<n;i++)
	{
		if(mark[i]==0)
		{
			count++;
			for(j=i*i;j<n;j=j+i)
			{
				mark[j]=1;
			}
		}
	}

	return count;
}


bool palin(ll n)
{
  ll reverse = 0, temp=0, i=0,j;
 
  //n=10;
  ll count=0;

  
   temp = n;
   reverse=0;

   while( temp > 0 )
     {
       j=temp%10;
       reverse=10*reverse+j;
       
       temp = temp/10;
     }

   if( n==reverse ) return true;
 
  return false;

}

int main()
{
	ll i,j,k;

	cin>>p>>q;
	//p=6;
	//q=4;
	ll max=10000000;
	ll prime=0;
	ll palindrome=0;

	ll ans=-1;

	sieve(max);

	mark[1]=1;

	for(i=1;i<max;i++)
	{
		if(!mark[i])prime++;
		if(palin(i))palindrome++;
		
		if(q*prime<=p*palindrome)
		ans=i;	
	}

	if(ans==-1)
	{
		cout<<"Palindromic tree is better than splay tree"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}

}