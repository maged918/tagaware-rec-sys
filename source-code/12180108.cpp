//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
char a[200000],b[200000];

int checkstr(int al,int ar,int bl,int br)
{
	if( (ar-al)%2 == 1 )
	{
		for(int i=0; i<(br-bl); i++)
		{
			if( a[al+i] != b[bl+i] )
				return 0;
		}

		return 1;
	}
	else
	{
		int mid = (ar-al)/2;

		if( checkstr(al,al+mid,bl,bl+mid)==1 && checkstr(al+mid,ar,bl+mid,br)==1 )
			return 1;
		if( checkstr(al,al+mid,bl+mid,br)==1 && checkstr(al+mid,ar,bl,bl+mid)==1 )
			return 1;
		else return 0;
	}
}

int main() {
	int n;
	cin>>a>>b;

	n=strlen(a);

	int ans=checkstr(0,n,0,n);

	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
