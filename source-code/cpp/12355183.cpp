//Language: MS C++


//In the name of God
//-----gmmj

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <map>
#include <sstream>
#include <ctime>
#include<iomanip>

#define Time printf("\nTime : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC);
#define Rep(I,N) for(int I=0;I<N;++I)
#define For(J,R,K) for(int J=R;J<K;++J)
#define MP make_pair
#define ALL(X) (X).begin(),(X).end()
#define SF scanf
#define PF printf
#define pii pair<int,int>
#define Ff first
#define Ss second
#define Sort(v) sort(ALL(v))
#define Test freopen("a.in","r",stdin);
#define Testout freopen("a.out","w",stdout);
#define pb push_back
#define RLL(X) scanf("%I64d",&X);
#define RRLL(X,Y) scanf("%I64d %I64d",&X,&Y);
#define WLL(X) printf("%I64d",X);
#define WWLL(X,Y) printf("%I64d %I64d",X,Y);
#define Loop(N) RLL(N)Rep(i,N)
#define Set(a,n) memset(a,n,sizeof(a))
#define MAXN 100000+9

typedef long long ll;

using namespace std;

ll a[MAXN];

int main()
{
//	Test
	ll n;
	while(cin>>n)
	{
		Rep(i,n)
			cin>>a[i];
		ll mx,mn;
		Rep(i,n)
		{
			mx=max(abs(a[0]-a[i]),abs(a[n-1]-a[i]));
			if(i>0 && i!=n-1)
				mn=min(abs(a[i]-a[i+1]),abs(a[i]-a[i-1]));
			else
			{
				if(!i)
					mn=a[1]-a[0];
				else
					mn=a[n-1]-a[n-2];
			}
			cout<<mn<<" "<<mx<<endl;
		}
	}
	return 0;
}