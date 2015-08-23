//Language: GNU C++


/*
ID: lisa.va1
PROG: test
LANG: C++11
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
 
using namespace std;
 
#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(auto it = (v).begin(); it != (v).end(); ++it)
 
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef long long ll;
 

double degsin(double a) {
	a = a/180*M_PI;
	return sin(a);
}

double degcos(double a) {
	a = a/180*M_PI;
	return cos(a);
}

double getArea(vector<double> x, vector<double> y) {
	double area = 0;
	int j = 5;
	rep(i, 0, 6) {
		area += (x[i]+x[j])*(y[j]-y[i]);
		j = i;
	}
	area /=2;
	return area;
}

int main(){
     vi side(6);
     rep(i, 0, 6) {
        cin >> side[i];
     }
     vector<double> x(6);
     vector<double> y(6);
     double curx, cury, angle;
     curx = cury = angle = 0;
     rep(i, 0, 6) {
     	x[i] = curx;
     	y[i] = cury;
     	curx = curx + side[i]*degcos(angle);
     	cury = cury + side[i]*degsin(angle);
     	angle += 60;
     }

     double area = getArea(x, y);

     double triangle = sqrt(3)/4;
     area = -area;
     cout << int(round(area/triangle)) << endl;
}