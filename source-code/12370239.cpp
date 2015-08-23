//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, maxi, mini;
	cin >> n;
	vector<long long> db(n,0);
	for(long long i = 0; i <n; i++) {
		cin >> db[i];		
	}
	
	
	for(long long i = 0; i < n; i++) {
		if(i==0) {
			maxi = db[n-1] - db[0];
			mini = db[1]-db[0];
		}
		else if(i<n-1) {
			mini = min(db[i]-db[i-1],db[i+1]-db[i]);
			maxi = max(db[i]-db[0],db[n-1]-db[i]);			
		}
		else{
			maxi = db[n-1] - db[0];
			mini = db[n-1] - db[n-2];
		}
	cout << mini <<" " << maxi << endl;	
	} 	
}
