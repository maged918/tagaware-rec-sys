//Language: GNU C++11


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;

int main(){
	int n;
	cin >> n;
	vector<ii> v(0);
	int left = 0;
	int right = 0;
	for (int i = 0; i < n; i++){
		int x,a;
		cin >> x >> a;
		v.push_back(ii(x,a));
		if (x < 0) left++;
		else right++;
	}
	sort(v.begin(), v.end());
	int total = 0;
	if (left == right) {
		for (int i = 0; i < n; i++) 
			total += v[i].second;
		cout << total << endl;
	} else if (left > right) {
		for (int i = 0; i < right*2 + 1; i++)
			total += v[n-i-1].second;
		cout << total << endl;
	} else {
		for (int i = 0; i < (left*2 + 1); i++)
			total += v[i].second;
		cout << total << endl;
	}
	return 0;
}