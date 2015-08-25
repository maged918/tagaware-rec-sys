//Language: GNU C++


#include<bits/stdc++.h>
using namespace std; 
long long t,s,q,cnt,temp; 
int main()
{
	cin>>t>>s>>q;
	cnt=1;
	while(1)
	{
		temp=s*(q-1);
		if(s+temp>=t)
			break;
		else
		{
			cnt++;
			s+=temp;
		}
	}
	cout<<cnt;
}
 
