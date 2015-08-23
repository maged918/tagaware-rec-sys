//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int n, res = 0;	
	vector< pair<int, int> > array_neg, array_pos; 
	cin >> n;
	for(int i = 0; i < n; i++){ 
		int a, b;
		cin >> a >> b;
		if(a < 0) array_neg.push_back(make_pair(a,b));
		else array_pos.push_back(make_pair(a,b));
	}
	sort(array_pos.begin(), array_pos.end());
	sort(array_neg.rbegin(), array_neg.rend());
	int length = array_pos.size() < array_neg.size() ? array_pos.size() : array_neg.size();
	for(int i = 0; i <= length; i++){
		if( i < length)
			res += array_pos[i].second + array_neg[i].second;
		else{
			if(array_pos.size() > array_neg.size()) res += array_pos[i].second;
			else if(array_pos.size() < array_neg.size()) res+= array_neg[i].second;
		}
	}	
	cout << res << endl;
	return 0;
}
