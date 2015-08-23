//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

using namespace std;

int n,m;

int main(){	
	cin>>n>>m;
	
	int below = m-1;
	int above = n-m;
	
	if(max(below,above) == below && n!=1)
		cout<<m-1<<endl;
	else if (n==1)
		cout<<1<<endl;
	else
		cout<<m+1<<endl;
	
	return 0;
}