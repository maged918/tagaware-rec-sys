//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;


int n, m;
bool b = false;
VI v;

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> m;
		if(m == 1) {
			b = true;
		}
	}
	if(b) {
		cout << "-1" << endl;
	}
	else {
		cout << "1" << endl;
	}
}
