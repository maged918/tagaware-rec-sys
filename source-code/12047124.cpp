//Language: GNU C++11


 
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;

vector<int> f[1010101];
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	int a[101010];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		f[a[i]].push_back(i);
	}
	int ma = 0;
	for(int i = 1; i <= 1000000; i++){
		ma = max(ma, (int)f[i].size());
	}
	int re = 9999999;
	int l, r;
	for(int i = 1; i <= 1000000; i++){
		if(f[i].size() == ma){
			if(f[i][f[i].size()-1]-f[i][0]+1 < re){
				re = f[i][f[i].size()-1]-f[i][0]+1;
				l = f[i][0]+1;
				r = f[i][f[i].size()-1]+1;
			}
		}	
	}
	cout << l << " " << r << endl;
	return 0;
}
