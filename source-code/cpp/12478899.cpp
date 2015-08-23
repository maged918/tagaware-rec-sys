//Language: GNU C++11


// -*- compile-command: "g++ -g -Wno-return-type -Wall -Wextra -DLOCAL -std=c++11 -D_GLIBCXX_DEBUG b.cpp -ob && ./b " -*-
#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<(n);i++)

int f[1000001],s[1000001],e[1000001];

main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,a;
	cin>>n;
	memset(s,-1,sizeof(s));
	int mx=0;
	f(i,n){
		cin>>a;
		mx=max(mx,++f[a]);
		if(!~s[a]) s[a]=i+1;
		e[a]=i+1;
	}
	int l=1,r=n;
	f(i,1000001){
		if(f[i]!=mx) continue;
		if(e[i]-s[i]<r-l)
			l=s[i],r=e[i];
	}
	cout<<l<<" "<<r<<'\n';
}
