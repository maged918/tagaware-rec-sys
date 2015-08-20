//Language: GNU C++


//Author : Utkarsh $axena

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define M 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
int tree[28][100000*6+5];
int lazy[28][100000*6+5];

lld query(int t,int i,int si,int sj,int qi,int qj)
{
	if(si==qi and sj==qj)return tree[t][i];
	int mid=(si+sj)/2;
	if(lazy[t][i]!=0)
	{
		return lazy[t][i]==1?qj-qi+1:0;
	}
	if(qj<=mid)return query(t,2*i,si,mid,qi,qj);
	else if(mid+1<=qi)return query(t,2*i+1,mid+1,sj,qi,qj);
	else
	{
		lld t1,t2;
		t1=query(t,2*i,si,mid,qi,mid);
		t2=query(t,2*i+1,mid+1,sj,mid+1,qj);
		return (t1+t2)%M;
	}
}
void update(int t,int i,int si,int sj,int qi,int qj,int laz,int q)
{
	if(qi>qj)return;
	//cerr<<t<<' '<<i<<' '<<si<<' '<<sj<<'\t'<<qi<<' '<<qj<<"\t\t"<<q<<endl;
	if(qi==0 and qj==0)
	{
		//just update
		if(laz==0)return;
		lazy[t][i]=laz;
		if(lazy[t][i]==1)
		{
			tree[t][i]=sj-si+1;
			return;
		}
		if(lazy[t][i]==-1)
		{
			tree[t][i]=0;
			return;
		}
		tree[t][i]=(tree[t][2*i]+tree[t][2*i+1])%M;
		return;
	}
	if(si==qi and sj==qj)
	{
		lazy[t][i]=q;
		if(lazy[t][i]==1)
		{
			tree[t][i]=sj-si+1;
			return;
		}
		if(lazy[t][i]==-1)
		{
			tree[t][i]=0;
			return;
		}
		tree[t][i]=(tree[t][2*i]+tree[t][2*i+1])%M;
		return;
	}
	int mid=(si+sj)/2;
	if(qj<=mid)
	{
		if(laz==0)
			laz=lazy[t][i];
		update(t,2*i,si,mid,qi,qj,laz,q);
		update(t,2*i+1,mid+1,sj,0,0,laz,q);
	}
	else if(mid+1<=qi)
	{
		if(laz==0)
			laz=lazy[t][i];
		update(t,2*i,si,mid,0,0,laz,q);
		update(t,2*i+1,mid+1,sj,qi,qj,laz,q);
	}
	else
	{
		if(laz==0)laz=lazy[t][i];
		update(t,2*i,si,mid,qi,mid,laz,q);
		update(t,2*i+1,mid+1,sj,mid+1,qj,laz,q);
	}
	lazy[t][i]=0;//broken lazy[t]
	tree[t][i]=(tree[t][2*i]+tree[t][2*i+1])%M;
}
int main()
{
	//fre;
	int N,Q;
	string S;
	cin>>N>>Q;
	cin>>S;
	for(int i=1;i<=N;++i)
	{
		update(S[i-1]-'a'+1,1,1,N,i,i,0,1);
	}
	/*for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=26;++j)
		{
			if(query(j,1,1,N,i,i))
			{
				cout<<(char)('a'+j-1);
				break;
			}
		}
	}*/
	int L,R,K;
	while(Q--)
	{
		scan(L);scan(R);scan(K);
		//cerr<<"\n\n\n\n\n\n\n";
		//cerr<<L<<' '<<R<<' '<<K<<endl;
		int done = 0;
		if(K==1)
		{
			for(int i=1;i<=26;++i)
			{
				int start = L+done;
				done += query(i,1,1,N,L,R);

				//cerr<<"\n\n\n\n\n\n\n";
				//cerr<<start<<' '<<L+done-1<<endl;
				update(i,1,1,N,L,R,0,-1);
				update(i,1,1,N,start,L+done-1,0,1);
			}
		}
		else
		{
			for(int i=1;i<=26;++i)
			{
				int end = R-done;
				done += query(i,1,1,N,L,R);
				update(i,1,1,N,L,R,0,-1);
				update(i,1,1,N,R-done+1,end,0,1);
			}
		}
	}
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=26;++j)
		{
			if(query(j,1,1,N,i,i))
			{
				cout<<(char)('a'+j-1);
				break;
			}
		}
	}
}











