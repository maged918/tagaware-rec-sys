//Language: GNU C++


#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 2000000000
#define MP make_pair
#define orta ((a+b)/2)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
using namespace std;
typedef  pair <int ,int> ii;
typedef  long long int lint;
int n,m,q,cevap;
string a;
int main()
{
	scanf("%d %d",&n,&m);
	cin >> a;
	for(int i=0;i<a.size()-1;i++)
		if(a[i]=='.' && a[i+1]=='.')
			cevap++;
	for(int i=0;i<m;i++)
	{
		int x;
		char c;
		scanf("%d %c",&x,&c);
		x--;
		if(a[x]==c || (a[x]!='.' && c!='.'))
		{
			printf("%d\n",cevap);	
			continue;
		}
		if(c=='.')
		{
			if(x>0 && a[x-1]=='.') cevap++;
			if(a.size()-1>x && a[x+1]=='.') cevap++;
		}
		else
		{
			if(x>0 && a[x-1]=='.') cevap--;
			if(a.size()-1>x && a[x+1]=='.') cevap--;			
		}
		a[x]=c;
		printf("%d\n",cevap);
	}
	
	
}
