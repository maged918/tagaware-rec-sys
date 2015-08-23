//Language: MS C++


#pragma region include

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
#include<time.h>
#include<set>
#include<vector>
#include<numeric>
#include<iomanip>
#include <bitset>
#include <functional>
using namespace std;

#pragma endregion

#pragma region define 
#define All(a) a.begin(), a.end()
#define _2d(a,row,col,type) type**a=new type*[row]; for (int i=0;i<row;i++) a[i]=new type[col];
#define rep(i,n) for(int i=0;i<int(n);i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define repi(i,a,n) for(int i=int(a);i<int(n);i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define scn(a,n) rep(i,n) cin>>a[i];
#define scn2(a,row,col) rep(i,row) rep(j,col) cin>>a[i][j];
#define prn(a,n) rep(i,n-1) cout<<a[i]<<" "; cout<<a[n-1]<<endl;
#define prn2(a,row,col) rep(i,row){rep(j,col-1) cout<<a[i][j]<<" "; cout<<a[i][col-1]<<endl;}
#define mp make_pair
#define Odd(x) x%2!=0
#define Even(x) x%2==0
#define Pi 3.14
#define INF 20000000000 // 2 billion
#define read freopen("in.in","r",stdin)
#define write freopen("out.out","w",stdout)
#define IOS  ios::sync_with_stdio(false)
#pragma endregion

#pragma region typedef

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi > vivi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, string> is;
typedef pair<int, int> ii;

#pragma endregion

int main(){
	int n; cin >> n;
	vector<bool>v(n+1, 0);
	vi a(n);
	int k = 1,x;
	vi ans;
	rep(i, n){
		cin >> a[i];
		if (a[i] <= n && !v[a[i]] )
			v[a[i]] = 1;
		else
			ans.push_back(i);
	}
	rep(i, ans.size()){
		while (v[k] )
			k++;
		v[k] = 1;
		a[ans[i]] = k;
	}
	rep(i, n)
		cout << a[i] << " ";
	return 0;
}