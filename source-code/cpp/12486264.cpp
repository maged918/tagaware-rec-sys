//Language: GNU C++11


#include <vector>
#include <iostream>

using namespace std;

std::vector<char> v;
//int nums[100000000];
std::vector<char> v2;

bool cmp(string &a, string &b){

	if(a.size() == 1)
		return a[0] == b[0];

	if(a.size() & 1){
		return a == b;

	}


	string a1 = a.substr(0, a.size()/2);
	string a2 = a.substr((a.size()/2), a.size());
	string b1 = b.substr(0, b.size()/2);
	string b2 = b.substr((b.size()/2), b.size());

	return (cmp(a1, b2) and cmp(a2, b1)) or (cmp(a1, b1) and cmp(a2, b2));


}


int main(){

	string a;
	string b;

	cin >> a;
	cin >> b;
	if(a.size()%2 == 1){
		if(a == b){
			cout << "YES" << endl;
			return 0;
		}else{
			
				cout << "NO" << endl;
				return 0;
			}
		}

	/*a.append(b);

	int n = a.size();

	for (int i = 0; i < n; ++i)
	{
		if(a[i] != a[n-1-i]){
			cout << "NO" << endl;
			return 0;
		}

	}*/

	if(cmp(a, b)){

		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	

}