//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e5+5;
int a[MAX_N];
int b[MAX_N];
int main(){
	int n;
	cin>>n;
	map <int,int> m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		m[a[i]]++;
	}
	int j=1;
	for (int i=1;i<=n;++i){
		if (m[i]==0) {
			b[j++]=i;
		}
	}
	j=1;
	for (int i=1;i<=n;++i){
//		cout<<m[a[i]]<<endl;
		if (m[a[i]]>1||a[i]>n){
			m[a[i]]--;
			a[i]=b[j++];		
		}
	}
	for (int i=1;i<=n;++i){
		cout<<a[i]<<' ';
	}
}
