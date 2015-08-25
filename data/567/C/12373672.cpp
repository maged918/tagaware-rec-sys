//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int val = 1000000000;
typedef long long int lli;

map < lli , lli > m1,m2;
vector < lli > poc;

int main() {
	
	lli n,k;
	cin >> n >> k;
	for ( int i = 0 ; i < n ; i ++ ) {
		lli a;
		scanf("%I64d",&a);
		poc.push_back(a);
	}
	for ( int i = n-1 ; i >= 2 ; i -- ) {
		//cout << m2[poc[i]] << endl;
		m2[poc[i]]++;
	}
	
	lli rez = 0;
	m1[poc[0]] ++;
	for ( int i = 1 ; i < n ; i ++ ) {
		if ( i != 1 ) m2[poc[i]] --;
		//cout << m1[poc[i]/k] << " " << m2[poc[i]*k] << endl;
		if ( poc[i] % k == 0 ) {
			rez += m1[poc[i]/k] * m2[poc[i]*k];
		}
		m1[poc[i]] ++;
	}
		
	cout << rez << endl;
	return 0;
}
		
	
