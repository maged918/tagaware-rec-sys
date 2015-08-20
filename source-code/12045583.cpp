//Language: GNU C++


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector< pair<int,int> > neg, pos;
int n,m,res;
int a,b;

int main(){
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a >> b;
		if (a < 0){
			neg.push_back(make_pair(-a,b));
		}
		else {
			pos.push_back(make_pair(a,b));
		}
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	if (pos.size() > neg.size()){
		m = neg.size();
		for (int i=0;i<m;i++){
			res += pos[i].second;
			res += neg[i].second;
		}
		res += pos[m].second;
	}
	else if (pos.size() < neg.size()){
		m = pos.size();
		for (int i=0;i<m;i++){
			res += pos[i].second;
			res += neg[i].second;
		}
		res += neg[m].second;
	}
	else {
		m = pos.size();
		for (int i=0;i<m;i++){
			res += pos[i].second;
			res += neg[i].second;
		}
	}
	cout << res << endl;
}
