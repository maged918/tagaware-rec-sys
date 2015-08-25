//Language: GNU C++11


#include <iostream>
using namespace std;

int l[100003], d[100003], n, i, maxi=100003, nr[100003];


void Dist(int x, int y)
{	++nr[x];
	if (x/2>0 && l[x/2]!=i)
	{	d[x/2]+=y+1;
		l[x/2]=i;
		Dist(x/2, y+1);
	}
	if (2*x<=maxi && l[2*x]!=i)
	{	d[2*x]+=y+1;
		l[2*x]=i;
		Dist(2*x, y+1);
	}
}

int main()
{	int x;
	cin>>n;
	for (i=1; i<=n; ++i)
	{	cin>>x;
		l[x]=i;
		Dist(x, 0);
	}
	int mini=2000000000;
	for (i=1; i<=maxi; ++i)
		if (nr[i]==n && mini>d[i])
			mini=d[i];
	cout<<mini<<'\n';
    return 0;
}
