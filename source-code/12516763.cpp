//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define INF 100010001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long llu;
typedef long double ld;

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define pp pop_back
#define len(vale) strlen(vale)
#define sz(vale) vale.size()
#define sq(A) ((A)*(A))
#define pc putchar
#define gc getchar
#define f(i12,fa,fb) for(i12=fa;i12<fb;i12++) 
#define fd(i12,fa,fb) for(i12=fa;i12>fb;i12--) 
//#define debug(args...) do {cerr << #args << ": "; DBG,args; cerr << endl;} while(0)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define bits(vale) __builtin_popcount(vale)

#define set1(array,val,sz) for(int i13=0;i13<sz;i13++)array[i13]=val;
#define set2(array,val,sz) for(int i13=0;i13<sz;i13++)for(int i14=0;i14<sz;i14++)array[i13][i14]=val;

#define all(a) a.begin(),a.end()
#define lb(a,x) (lower_bound(all(a),x)-a.begin())
#define ub(a,x) (upper_bound(all(a),x)-a.begin())

#define exectime() cout<<"execution time ="<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;


#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

// IO
#define si(vale) scanf("%d",&vale)
#define pi(vale) printf("%d\n",vale)
#define sl(vale) scanf("%lld",&vale)
#define pl(vale) printf("%lld\n",vale)
#define ss(vale) scanf("%s",vale)
#define ps(vale) printf("%s\n",vale)
#define sld(vale) cin>>vale
#define pld(vale) cout<<std::setprecision(15)<< fixed <<vale <<endl
//

#define tcs() int testcase; si(testcase);while(testcase--) 
void io()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
}

typedef pair<int,int> pr;
typedef vector<int> vt;

bool deg=false;
const int N=300011;
char a[N];
int l[N]={0};
int r[N]={0};

int main(){
    //io();
    //clock_t tStart = clock();
    int i,j,n,q;
    si(n),si(q);
    ss(a); //trace1(a);
    fd(i,n,0)
    	a[i]=a[i-1];
    int ct=0;
    ll as=0;	
    a[n+1]='\0';
    f(i,1,n+2)
    {
    	if(a[i]=='.')
    		ct++;
    	else
    	{	//trace2(ct,as);
    		if(ct>0)
    		as+=(ct-1);
    		//trace1(as);
    		ct=0;
    	}
    	l[i]=ct;
    }
    //trace1(as);
    ct=0;
    fd(i,n,0)
    {
    	if(a[i]=='.')
    		ct++;
    	else
    		ct=0;
    	r[i]=ct;
    }
    a[0]='\0'; a[n+1]='\0';
    char c;
    while(q--)
    {
    	scanf("%d %c",&i,&c); //trace3(i,c,as);

    	if((a[i]=='.' && c=='.') || (a[i]!='.' &&c!='.'))
    		{	pl(as);a[i]=c;
    			continue;
    		}
    	else
    	{
    		if(a[i]=='.' && c!='.')
    		{
    			if(a[i+1]!='.' && a[i-1]!='.')
    			{	pl(as);a[i]=c;
    				continue;
    			}
    			else
    			{
    				if(a[i-1]!='.' || a[i+1]!='.')
    					as-=1;
    				else
    					as-=2;
    			}
    		}

    		else if(a[i]!='.' && c=='.')
    		{
    			if(a[i+1]!='.' && a[i-1]!='.')
    			{	pl(as);a[i]=c;
    				continue;
    			}
    			else
    			{
    				if(a[i-1]!='.' || a[i+1]!='.')
    					as+=1;
    				else
    					as+=2;
    			}			
    		}
    		a[i]=c;
    	}
    	pl(as);

    }


    //exectime();
    return 0;        
}
