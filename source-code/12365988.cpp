//Language: GNU C++



//~        Author : Sarvesh Mahajan                             
//               IIIT,Hyderabad                                   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define For(i,a,b) for(i=a;i<b;i++)
#define loop(i,b) for(i=0;i<b;i++)
#define Loop(i,b) for(i=1;i<=b;i++)
#define pi(n) cout<<n<<' '
#define si(n) cin>>n
const int MOD=1e9+7;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
#define F first
#define S second
#define sz(x) (int) x.size()
#define pLL(x) cout<<x<<' '
#define fill(x,c) memset(x,c,sizeof(x))
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#ifdef DEBUG
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#else
#define DB(x)
#define DB2(x,y)
#define DB3(x,y,z)
#endif




const int N=1e6+5;
int f[N];
int a[200];
bool seen[N];
int main()
{
ios_base::sync_with_stdio(false);
int n,t,m,l,k,ans,i,j,res=0,fl;
t=1;
//cin>>(t);
while(t--)
{
	cin>>n;
	string s;
	int x;
	int req=0,maxi=0;
	loop(i,n)
	{
		cin>>s>>x;
		if( s == "+")
			a[i]=x;
		else
			a[i]=-x;

	}


	set<int> active;
	loop(i,n)
	{
		if(a[i]<0 and !seen[-a[i]])
			active.insert(-a[i]);
		if(a[i]>0)
		seen[a[i]]=1;
	}
	maxi=active.size();


	loop(i,n)
	{
		if(a[i]>0)
			active.insert(a[i]);
		else
			active.erase(-a[i]);

		maxi=max(maxi,(int)active.size());
	}



	cout<<maxi<<'\n';





}
return 0;
}
