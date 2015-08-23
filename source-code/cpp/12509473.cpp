//Language: GNU C++


#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m;
int main(){
	cin >> n >> m;
	int a = m-1;
	int b = n-m;
	if(n==1 && m==1){
		cout << 1;
		return 0;
	}
	if(a>=b) cout << a;
	else cout << m+1;
}