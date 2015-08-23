//Language: GNU C++11


/*
PROG:kerim
LANG:C++
*/
#include<bits/stdc++.h>
#define MAXN 100009
#define INF 1000000007
#define LLINF 1000000000000000007
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ppb() pop_back()
#define tr(i, c) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
int n,m;
char rr[MAXN];
int ra[27],lazy[4*MAXN],s[4*MAXN][27];
void upd(int nd,int x,int y,int v)
{
	lazy[nd]=v;
	for(int i=1;i<=26;i++)
	s[nd][i]=0;
	s[nd][v]=(y-x+1);	
}
void shift(int nd,int x,int y)
{
	if(lazy[nd]==0)
		return;
	int mid=(x+y)>>1;	
	upd(nd*2,x,mid,lazy[nd]);	
	upd(nd*2+1,mid+1,y,lazy[nd]);
	lazy[nd]=0;	
}
void modi(int l,int r,int v,int nd,int x,int y)
{
	if(l>y or r<x)	
		return;
	if(l<=x and y<=r){
		upd(nd,x,y,v);
		return;
	}
	shift(nd,x,y);
	int mid=(x+y)>>1;
	modi(l,r,v,nd*2,x,mid);
	modi(l,r,v,nd*2+1,mid+1,y);
	for(int i=1;i<=26;i++)
		s[nd][i]=s[nd*2][i]+s[nd*2+1][i];
}
void tap(int x,int y,int nd)
{
	if(x==y) {
		for(int i=1;i<=26;i++)
			if(s[nd][i]!=0)
				cout<<char(i+96);
		return;		
	}
	shift(nd,x,y);	
	int mid=(x+y)>>1;		
	tap(x,mid,nd*2);
	tap(mid+1,y,nd*2+1);
}
void init(int nd,int x,int y)
{
	if(x==y)
	{
		s[nd][int(rr[x])-96]=1;
		return;	
	}
	int mid=(x+y)>>1;
	init(nd*2,x,mid);
	init(nd*2+1,mid+1,y);
	for(int i=1;i<=26;i++)
		s[nd][i]=s[nd*2][i]+s[nd*2+1][i];
}
void tap1(int l,int r,int nd,int x,int y)
{
	if(y<l or x>r)
	return;
	if(l<=x and y<=r)
	{
		for(int i=1;i<=26;i++)
		ra[i]+=s[nd][i];
		return;
	}
	shift(nd,x,y);
	int mid=(x+y)>>1;	
	tap1(l,r,nd*2,x,mid);
	tap1(l,r,nd*2+1,mid+1,y);
}
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%c",&rr[i]);
	}
	init(1,1,n);
	while(m--){
		int l,r,k;
		cin>>l>>r>>k;
		for(int i=1;i<=26;i++)
			ra[i]=0;
		tap1(l,r,1,1,n);
		if(k==1){
			int last=l;
			for(int i=1;i<=26;i++)
				if(ra[i])
					modi(last,last+ra[i]-1,i,1,1,n),last+=ra[i];		
		}
		else{
			int last=l;
			for(int i=26;i>=1;i--)
				if(ra[i])
					modi(last,last+ra[i]-1,i,1,1,n),last+=ra[i]; 
		}
	}
	tap(1,n,1);
}
