//Language: GNU C++


#include<iostream>
using namespace std;

int a[6];

int solve(int under)
{
	int total = 0;
	for (int i = 0; i < under; i++){
		total += 2 * i + 1;
	}
	return total;
}

int main()
{
	for (int i = 0; i < 6; i++){
		cin >> a[i];
	}
 
	cout << solve(a[2] + a[3] + a[4]) - solve(a[0]) - solve(a[2]) - solve(a[4]) << endl;
	return 0;
}