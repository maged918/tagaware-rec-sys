//Language: GNU C++


#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,ii ) for( typeof(gg.begin()) ii=gg.begin();ii!=gg.end();ii++)
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
typedef long double ld;

inline ll input(void)
{
	char t;
	ll x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
    while(t>=48 && t<=57)
    {
        x=(x<<3)+(x<<1)+t-48;
        t=getchar();
    }
	if(neg)
		x=-x;
	return x;
}

inline void output(ll x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

int main()
{
ll n,k,i,a[200010],ans=0;
n=input();
k=input();
for(i=0;i<n;i++) a[i]=input();
map <ll,ll> m[2];
set <ll> :: iterator ii; 
set <ll> s[2];
for(i=0;i<n;i++)
{
	if (a[i]%k==0)
	{
		ii=s[1].find(a[i]/k);
		if (ii!=s[1].end())
			ans+=m[1][a[i]/k];
		ii=s[0].find(a[i]/k);
		if (ii!=s[0].end())
		{
			s[1].insert(a[i]);
			m[1][a[i]]+=m[0][a[i]/k];
		}
	}
	s[0].insert(a[i]);
	m[0][a[i]]++;
}
output(ans);
return 0;
}
