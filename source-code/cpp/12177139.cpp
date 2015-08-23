//Language: GNU C++


#include <iostream>

using namespace std;

int main(){
 int n;
 cin >> n;
 int a[1000],i,flag;
 flag = 0;
 for (i=0; i<n; i++){
 	cin >> a[i];
	if (a[i] == 1) flag = 1;}
 if (flag == 1) cout << "-1";
 if (flag == 0) cout << "1"; 
 return 0;
}
