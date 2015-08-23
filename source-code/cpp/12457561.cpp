//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define sz(v) (int)v.size()
#define eps 1e-10
#define all(v) v.begin(), v.end() 
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define chk(a,k) ((bool)(a&(1<<(k))))
#define set0(a,k) (a&(~(1<<(k))))
#define set1(a,k) (a|(1<<(k)))
#define in(v, x) (find(all(v),x) != v.end()) 
#define re return
#define sum(v) accumulate(v.begin(),v.end(),(ld)0)
#define tr(v,it) for(auto it=v.begin();it != v.end();it++)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define pi 3.1415926535897932384626433832795
#define MOD 1000000007LL
#define print(v) for (auto& i:v) cout<<i<<endl 
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;

#define N 1250000+5

int C=0;
template<class T> vector<bool> sieve(T n) {
	vector<bool> prime;
	for(T i=0; i<=n; i++) {
		prime.push_back(true);
	}
	prime[0]=false;
	prime[1]=false;
	long long m=sqrtl(n);
	for(T i=2; i<=m; i++) {
		if(prime[i]) {
			for(T k=i*i; k<=n; k+=i) {
				prime[k]=false;
			}
		}
	}
	return prime;
}
vector<bool> P;

bool palin[N];

int C1[N], C2[N];

string tos(int a) {
	stringstream ss;
	ss << a;
	string str=ss.str();
	return str;
}

bool ok(int i) {
	string s=tos(i);
	string r=s;
	rev(s);
	if(s==r)re 1;
	re 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<setprecision(10);
#ifndef ONLINE_JUDGE
	freopen("Data/input.txt", "r", stdin);
	freopen("Data/output.txt", "w", stdout);
#endif
	P=sieve(N);
	for(int i=1; i<sz(P); i++) {
		if(P[i]) C++;
	}
	int p=1;
	for(int i=1; i<=N; i++) {
		if(ok(i)) palin[i]=1;
	}

	for(int i=1; i<N; i++) {
		if(P[i]) C1[i]=C1[i-1]+1;
		else C1[i]=C1[i-1];
		if(palin[i]) C2[i]=C2[i-1]+1;
		else C2[i]=C2[i-1];
	}
	ld a, b;
	cin>>a>>b;
	for(int i=N-1; i>=1; i--) {
		if((ld)C1[i]/(ld)C2[i]<=a/b) {
			cout<<i;
			re 0;
		}
	}
	cout<<C;
	return 0;
}
