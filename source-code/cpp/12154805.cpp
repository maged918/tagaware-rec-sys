//Language: GNU C++


/****** BISMILLAH HIR RAHMANIR RAHIM ******/

/*

"For indeed, with hardship [will be] ease. Indeed, with hardship [will be] ease."

-- Surah Inshirah (94:5-6)


And We will surely test you with something of fear and hunger and a loss of wealth and lives and fruits, but give good tidings to the patient,
Who, when disaster strikes them, say, "Indeed we belong to Allah , and indeed to Him we will return."
Those are the ones upon whom are blessings from their Lord and mercy. And it is those who are the [rightly] guided.

-- Surah Al-Baqarah (2:155-157)

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <int, int> pii;

#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define MAX 100002
#define debug cout<<"A"<<"\n"
#define prnt(a) cout<<a<<"\n"
#define mod 1000000007
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lc ((node)<<1)
#define rc ((node)<<1|1)
#define VecPrnt(v) FOR(j,0,v.size()) cout<<v[j]<<" "; cout<<endl
#define endl "\n"


/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}

inline ll power(ll a, ll b)
{
	ll multiply=1;
	FOR(i,0,b)
	{
		multiply*=a;
	}
	return multiply;
}

/****** END OF HEADER ******/

char s[100005];
int Tree[28][400005], Lazy[28][400005];

void build(int node, int l, int r)
{
	if(l==r)
	{
		Tree[s[l]-'a'][node]=1;
		FOR(i,0,26) Lazy[i][node]=-1;
		return;
	}

	int mid=(l+r)/2;

	build(lc,l,mid);
	build(rc,mid+1,r);

	FOR(i,0,26)
	{
		Lazy[i][node]=-1;
		Tree[i][node]=Tree[i][lc]+Tree[i][rc];
	}
}

void pushToChild(int node, int l, int r, int i, int val)
{
	Tree[i][node]=(r-l+1)*val;
	Lazy[i][node]=val;
}

void push_down(int node, int i, int l, int r, int val)
{
	if(Lazy[i][node]==-1) return;
	if(l==r) return;

	int mid=(l+r)/2;

	pushToChild(lc,l,mid,i,val);
	pushToChild(rc,mid+1,r,i,val);

	Lazy[i][node]=-1;
}

void update(int node, int l, int r, int x, int y, int val, int i)
{
	if(x>r || y<l) return;

	if(x<=l && r<=y)
	{
		Lazy[i][node]=val;
		Tree[i][node]=val*(r-l+1);
		push_down(node,i,l,r,Lazy[i][node]);
		return;
	}

	push_down(node,i,l,r,Lazy[i][node]);

	int mid=(l+r)/2;

	update(lc,l,mid,x,y,val,i);
	update(rc,mid+1,r,x,y,val,i);

	Tree[i][node]=Tree[i][lc]+Tree[i][rc];
}

int query(int node, int l, int r, int x, int y, int i)
{
	if(x>r || y<l) return 0;

	if(x<=l && r<=y)
	{
		return Tree[i][node];
	}

	push_down(node,i,l,r,Lazy[i][node]);

	int mid=(l+r)/2;

	return query(lc,l,mid,x,y,i)+query(rc,mid+1,r,x,y,i);
}

void findAns(int node, int l, int r, int i)
{
	if(!Tree[i][node]) return;

	if(l==r)
	{
		s[l]=i+'a';
		return;
	}

	push_down(node,i,l,r,Lazy[i][node]);

	int mid=(l+r)/2;

	findAns(lc,l,mid,i);
	findAns(rc,mid+1,r,i);
}

int main()
{
	// ios_base::sync_with_stdio(0); 
	// cin.tie(NULL); cout.tie(NULL);
	// freopen("in.txt","r",stdin);

	int n, q, a, b, t;
	int cnt[30];

	scanf("%d%d", &n, &q);

	scanf("%s", s+1);

	build(1,1,n);

	FOR(i,0,q)
	{
		scanf("%d%d%d", &a, &b, &t);

		// cout<<a<<" "<<b<<" "<<t<<endl;

		FOR(i,0,26)
			cnt[i]=query(1,1,n,a,b,i);

		int start;

		if(t==0) start=b; else start=a;

		FOR(i,0,26)
		{
			if(cnt[i]==0) continue;

			update(1,1,n,a,b,0,i);

			// debug;

			if(t==1)
			{
				update(1,1,n,start,start+cnt[i]-1,1,i);
				start+=cnt[i];
			}

			else
			{
				update(1,1,n,start-cnt[i]+1,start,1,i);
				start-=cnt[i];
			}
		}
	}

	FOR(i,0,26)
		findAns(1,1,n,i);

	prnt(s+1);

	return 0;
}






