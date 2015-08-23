//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define pb push_back
#define ll long long
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()
#define gt greater<int>()
#define mod 1000000007
#define maxn 65540
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
int main(){
	long long n,m;
	scanf("%lld%lld",&n,&m);
	if(n%2==0){
		if(m-1+1>n-m+1){
			printf("%lld\n",m-1);
		}
		else{
			printf("%lld\n",m+1);
		}
	}
	else{
		if(m==(1+n)/2){
			if(m!=1)
				printf("%lld\n",m-1);
			else
				printf("%lld\n",m);
		}
		else if(m-1+1>n-m+1){
			printf("%lld\n",m-1);
		}
		else{
			printf("%lld\n",m+1);
		}
	}

    return 0;
}