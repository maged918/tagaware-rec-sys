//Language: MS C++


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <memory.h>
using namespace std;

const int Nmax=2e6+17;
bool used[Nmax]={0};

inline int next (int x){
	int i, z;
	vector <int> v;
	while(x){
		v.push_back(x%10); x/=10;
	}

	for(i=0, z=v.size()-1; i<z; i++, z--);
	int p = 1;
	for(; i<v.size() && p; i++, z--) {
		p=0;
		if(i==z) v[i]++; 
		else{
			v[i]++; v[z]++;
		}
		if(v[i]==10) { v[i]=0; p=1; } 
		if(v[z]==10) v[z]=0;
	}
	if(p){ v.push_back(1);
	v[0]=1; for(int i=1; i<v.size()-2; i++) v[i]=0; }
	for(int i=v.size()-1; i>=0; i--) { x*=10; x+=v[i]; }
	return x;
}

int main (void){
	//freopen("i.txt","r",stdin);
	//freopen("o.txt", "w+", stdout);
	//std::ios::sync_with_stdio(false);

	int p, q, cur=0, cur1=0, x=1, ans=0;
	double long k;
	cin >> p >> q;
	k = double(p)/q;

	for(long long i=2; i<Nmax; i++) if(used[i]==0) for(long long z=i*i; z<Nmax; z+=i) used[z]=1;
	

	
	for(int i=1; i<Nmax ; i++) {
		if(used[i]==0 && i>=2) cur++;
		if(i==x) { cur1++; x=next(x); }

		if(cur<=cur1*k) 
			ans = i;
	}
	if(ans!=0) cout << ans;
	else cout << "Palindromic tree is better than splay tree";
}