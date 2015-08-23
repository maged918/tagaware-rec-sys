//Language: GNU C++11


#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

ll C[72][72] = {0};
vector<vi> geq;
vector<vi> bigger;
int INF = 10000000;

void DP(int lower,int  upper,int  newLower,int  newUpper,int  new1,int  new2) {
	//cout << newLower << " " << newUpper << endl;
	for (int big : bigger[new1])
		if (big < lower || big > upper)
			return;

	for (int big : bigger[new2]) 
		if (big < lower || big > upper) 
			return;

	for (int big : geq[new1]) 
		if (big < newLower || big > newUpper) 
			return;
		
	for (int big : geq[new2]) 
		if (big < newLower || big > newUpper) 
			return;
		
	C[newLower][newUpper] += C[lower][upper];
	//cout << C[newLower][newUpper] << endl;
}


int main(){
	int n,k;
	cin >> n >> k;

	geq = vector<vi>(2*n+1, vi(0));
	bigger = vector<vi>(2*n+1, vi(0));

	for (int i = 0; i < k; i++) {
		int x,y;
		string comp;
		cin >> x >> comp >> y;
		if (comp == "=") {
			geq[x].push_back(y);
			geq[y].push_back(x);
		} else if (comp == "<") {
			bigger[x].push_back(y);
		} else if (comp == ">") {
			bigger[y].push_back(x);
		} else if (comp == ">=") {
			geq[y].push_back(x);
		} else if (comp == "<=") {
			geq[x].push_back(y);
		} else {
			//cout << "FUCK" << endl;
			return 0;
		}
	}

	for (int i = 1; i <= 2*n-1; i++) {
		int try1 = i;
		int try2 = i+1;
		if (!bigger[try1].empty()) continue;
		if (!bigger[try2].empty()) continue;
		bool works = true;
		for (int big : geq[try1]) {
			if (big != try1 && big != try2) {
				works = false;
				break;
			}
		}
		if (works)
		for (int big : geq[try2]) {
			if (big != try1 && big != try2){
				works = false;
				break;
			}
		}
		if (works) C[i][i+1] = 1;
	}

	for (int m = 2; m<= n; m++) {
		for (int i = 1; i + 2*(m-1) - 1 <= 2*n; i++) {
			int lower = i;
			int upper = i + 2*(m-1) - 1;
			if (lower >= 3) {
				// fill two slots to the left with new.
				int newLower = lower - 2;
				int newUpper = upper;
				int new1 = lower - 2;
				int new2 = lower - 1;
				DP(lower, upper, newLower, newUpper, new1, new2);
			}
			if (lower >=2 && upper <= 2*n-1) {
				int newLower = lower - 1;
				int newUpper = upper + 1;
				int new1 = lower - 1;
				int new2 = upper + 1;
				DP(lower, upper, newLower, newUpper, new1, new2);
			}
			if (upper <= 2*n-2) {
				int newLower = lower;
				int newUpper = upper + 2;
				int new1 = upper + 2;
				int new2 = upper + 1;
				DP(lower, upper, newLower, newUpper, new1, new2);
			}
		}
	}
	cout << C[1][2*n] << endl;



}