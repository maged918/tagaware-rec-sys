//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <climits>
#include <map>
#include <iostream>
#define ll long long
using namespace std;

int main(){
	ll n,k;
	ll temp;
	map<ll, ll> m,n1;
	//scanf("%d %d",&n,&k);
	cin >> n >> k;
	ll arr[n];
	ll count = 0;
	for(ll i=0;i<n;i++){
		cin >> temp;
		if(temp%k == 0){
			count += n1[temp/k];
			n1[temp] += m[temp/k];
		}
		m[temp]++;
	}
	cout << count << endl;
	
	return 0;
}
	
