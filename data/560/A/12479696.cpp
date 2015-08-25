//Language: GNU C++11


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 100003

using namespace std;

int n, v[1001];

int main(void){
	cin >> n;
	int ans = 1;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] == 1) ans = -1;
	}
	cout << ans << endl;
	return 0;
}