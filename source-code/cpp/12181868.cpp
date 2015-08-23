//Language: GNU C++11


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string s1, s2;

bool eql(string::iterator b1, string::iterator e1, string::iterator b2, string::iterator e2) {
	int ss1 = e1 - b1;
	int ss2 = e2 - b2;
	if(ss1 != ss2){
		return false;
	} 
	if(ss1%2 == 1) {
		for(int i = 0; i < ss1; ++i) {
			if(*(b1+i) != *(b2+i))
				return false;
		}
		return true;
	} else {

		bool tmp = true;
		for(int i = 0; i < ss1; ++i) {
			if(*(b1+i) != *(b2+i)) {
				tmp = false;
				break;
			}
		}
		if(tmp) return true;
		auto m1 = b1 + ss1/2;
		auto m2 = b2 + ss2/2;
		/*
		if(eql(b1, m1, m1, e1)) {
			return eql(b1, m1, b2, m2) && eql(b2, m2, m2, e2);
		} else if(eql(b1, m1, b2, m2)) {
			return eql(m1, e1, m2, e2);
		} else {
			return eql(b1, m1, m2, e2) && eql(m1, e1, b2, m2);
		}
		*/
		return (eql(b1, m1, b2, m2) && eql(m1, e1, m2, e2)) || (eql(b1, m1, m2, e2) && eql(m1, e1, b2, m2));
	}
	return true;
}

int main() {
	cin >> s1;
	cin >> s2;
	
	if(eql(s1.begin(), s1.end(), s2.begin(), s2.end())) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
