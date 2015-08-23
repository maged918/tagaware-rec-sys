//Language: GNU C++


#include<bits/stdc++.h>

//Author DBug<Deepak Sharma>

#define forn(i,n) for(long int i=0;i<n;i++)
#define fora(i,a,b) for(long int i=a;i<b;i++)
#define vi(v,n) int t;for(int i=0;i<n;i++){cin>>t;v.push_back(t);}
#define vo(v) for(int i=0;i<v.size();i++){cout<<v[i]<<",";}cout<<endl;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	long int n,m,k;
	cin>>n>>m;
	if(n==1 && m==1){
		cout<<1<<endl;
	}
	else{
		if(n%2==0){
			k = (n+1)/2;
		}
		else{
			k=n/2;
		}
		if(m>k){
				cout<<m-1<<endl;
		}
		else{
			cout<<m+1<<endl;
		}
	}	
}
