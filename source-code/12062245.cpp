//Language: MS C++


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,a,b,c=0,d=0,ans=0; cin >> n;
	pair<int, int>minus[101], plus[101];
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		if (a > 0) { 
			plus[c].first = a; plus[c].second = b; c++;
		}
		else {
			minus[d].first = a; minus[d].second = b; d++;
		}
	}
	sort(plus, plus + c); sort(minus, minus + d);
		c > d ? b = d + 1 : b = c + 1;
	for (int i = 0; i < b; i++)
			if(plus[i].second > 0)
				ans += plus[i].second;
	for (int i = d-1; i >=d-b; i--)
			if(minus[i].second > 0) 
			     ans += minus[i].second;		
	cout << ans;
}