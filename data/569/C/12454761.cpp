//Language: GNU C++11


#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF 1<<30
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ll long long
#define ull unsigned long long

vector<int> P;

void prime(int n){
	int a[n+1];
	REP(i,n){
		a[i]=i;
	}
	for(int i=2;i<=n;i++){
		if(a[i]==i){
			P.pb(a[i]);
			for(int j=2*i;j<=n;j+=i) a[j]=i;
		}
	}
}

bool palad(int i){
	int c=0;int tmp=i;
	while(tmp>0){tmp/=10;c++;}
	int a[c];int j=0;
	tmp=i;
	while(tmp>0){
		a[j]=tmp%10;
		tmp/=10;
		j++;
	}
	REP(i,c){
		if(a[i]!=a[c-1-i])return false;
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int p,q;
	cin>>p>>q;
	int n=1200000;
	prime(n);
// 	REP(i,100)cout<<P[i]<<endl;	 
	int cnt=0;
	int ans=0;
	FOR(i,1,n){
		if(palad(i)){
			cnt++;
		}
		auto it=upper_bound(P.begin(),P.end(),i);
		it--;
		int len=it-P.begin()+1;
		if(q*len<=p*cnt) {ans=i;}
	}
	if(ans!= n-1)cout<<ans<<endl;
	else cout<<"Palindromic tree is better than splay tree"<<endl;
}
