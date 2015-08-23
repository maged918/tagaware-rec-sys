//Language: GNU C++


#include <iostream>

using namespace std;

const int maxn = 4000+10;
const long long MMOD = 1000000000+7;
int nn;

long long A[maxn][maxn], Ap[maxn][maxn];

int main() {
	cin >> nn;

	Ap[0][0] = 1;
	for (int n=1; n<=nn; n++) {
		for (int k=0; k<=n; k++) {
			Ap[n][k] = Ap[n-1][k] * k + (k>0?Ap[n-1][k-1]:0);
			Ap[n][k] %= MMOD;
			A[n][k] = A[n-1][k] * k + A[n-1][k] + Ap[n-1][k] + (k>0?A[n-1][k-1]:0);
			A[n][k] %= MMOD;
		}
	}

	/*
	cerr << " AP " << endl;
	for (int n=0; n<=nn; n++) {
		for (int k=0; k<=n; k++) {
			cerr << Ap[n][k] << " ";
		}
		cerr << endl;
	}
	cerr << endl;

	cerr << " A " << endl;
	for (int n=0; n<=nn; n++) {
		for (int k=0; k<=n; k++) {
			cerr << A[n][k] << " ";
		}
		cerr << endl;
	}
	cerr << endl;
*/

	long long sum = 0;
	for (int k=0; k<=nn; k++) {
		sum += A[nn][k];
		sum %= MMOD;
	}

	cout << sum << endl;

	return 0;
}
