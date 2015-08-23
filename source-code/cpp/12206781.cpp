//Language: GNU C++


#include <iostream>
#include <cstring>
using namespace std;

string solve(string cad){
	string res = "";
	int l = cad.length();
	if (l % 2 == 1){
		res = cad;
	} else {
		string a = cad.substr(0, l/2);
		string b = cad.substr(l/2, l/2);
		a = solve(a);
		b = solve(b);

		if (a > b)
			swap(a, b);
		res = a + b;
	}

	return res;
}

int main(){
	string a, b;
	cin>>a>>b;

	if (solve(a) == solve(b))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}