//Language: GNU C++11


//Vatsal Gupta
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cctype>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset> 
#include <utility>
#include <set>
#include <numeric> 

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define lli long long int
#define ulli unsigned long long int

#define PB push_back
#define POB pop_back
#define gc getchar
#define pc putchar
#define F first
#define S second
#define SET(a,b) memset(a,b,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)(a.size())

#define loop(i,a,b) for(int i=a; i<b; i++)  

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define INF 1000000000  //1 billion (10^9)
#define MOD 10000000	//(10^7)

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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int main()
{
	ios::sync_with_stdio(false);

	int a, b, c, d, e, f;
	lli final=0;
	cin>> a>> b>> c>> d>> e>> f;

	loop(i,1,min(b,f)+1)
		final+= ((2*a)+(2*i)-1);
	loop(i,1,min(c,e)+1)
		final+= ((2*d)+(2*i)-1);
	final+= ((max(e,c)-min(e,c))*(2*(d+min(e,c))));

	cout<< final;



	return 0;
}
