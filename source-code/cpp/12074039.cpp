//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};	
//////////////////////

const int N = 100010;

struct segtree
{
	int tr[4*N], lz[4*N];
	segtree()
	{
		memset(tr,0,sizeof tr);
		memset(lz,INF,sizeof lz);
	}

	void init()
	{
		memset(tr,0,sizeof tr);
		memset(lz,INF,sizeof lz);
	}

	void propagate( int no, int l, int r )
	{
		if( lz[no] == INF ) return;
		tr[no] = lz[no] * (r-l+1);
		if( l != r )
		{
			int nxt = (no<<1);
			lz[nxt] = lz[no];
			lz[nxt+1] = lz[no];
		}
		lz[no] = INF;
	}

	void update( int no, int l, int r, int i, int j, int val )
	{
		propagate(no,l,r);
		if(r<i || l>j) return;
		if( l>=i && r<=j )
		{
			lz[no] = val;
			propagate(no,l,r);	
			return;
		} 
		int nxt = (no<<1), mid = (l+r)>>1;
		update(nxt,l,mid,i,j,val); update(nxt+1,mid+1,r,i,j,val);
		tr[no] = tr[nxt]+tr[nxt+1];
	}

	int query( int no, int l, int r, int i, int j )
	{
		propagate(no,l,r);
		if(r<i || l>j) return 0;
		if( l>=i && r<=j ) return tr[no];
		int nxt = (no<<1), mid = (l+r)>>1;
		return query(nxt,l,mid,i,j)+query(nxt+1,mid+1,r,i,j);
	}

};

char s[N];
segtree tr[26];
int cnt[26];

int main()
{
	//ios::sync_with_stdio(0);
	int n,q; scanf("%d %d",&n,&q); scanf(" %s",s);
	for(int i=0;i<n;++i) tr[s[i]-'a'].update(1,0,n-1,i,i,1);
	while(q--)
	{
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<26;++i)
		{
			cnt[i] = tr[i].query(1,0,n-1,a,b);
			tr[i].update(1,0,n-1,a,b,0);
			
		}
		if(c)
		{
			for(int i=0;i<26;++i)
			{
				tr[i].update(1,0,n-1,a,a+cnt[i]-1,1);
				a+=cnt[i];
			}
		}
		else
		{
			for(int i=25;i>=0;--i)
			{	
				tr[i].update(1,0,n-1,a,a+cnt[i]-1,1);
				a+=cnt[i];
			}
		}

	}
		for(int i=0;i<n;++i) for(int j=0;j<26;++j) if( tr[j].query(1,0,n-1,i,i) ) printf("%c",j+'a');
		printf("\n");

	
	return 0;
}	