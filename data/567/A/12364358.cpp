//Language: MS C++


#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include <cmath>
using namespace std;
//ifstream cin("input.txt");
//ofstream cout("output.txt"); 
int n, i, a[1000005];
long long int  mina = 2000000005, minb = 2000000005, maxa, maxb;
int main()
{
    cin >> n;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	for (i = 0; i < n; i++){
		if (i == 0){
			mina = abs (a[i] - a[i + 1]);
			maxa = abs (a[i] - a[n - 1]);
		}
		if (i == n - 1){
			mina = abs (a[i] - a[i - 1]);
			maxa = abs (a[0] - a[i]);
		}
		if (i != n - 1 && i != 0){
			mina = abs (a[i] - a[i - 1]);
			maxa = abs (a[i] - a[n - 1]);
			minb = abs (a[i] - a[i + 1]);
			maxb = abs (a[i] - a[0]);
		}
		cout << min(mina, minb) << ' ' << max (maxa, maxb) << endl;
	}
    return 0;
}