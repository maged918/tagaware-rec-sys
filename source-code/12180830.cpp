//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main(){
	int s[6];
	for(int i=0;i<6;i++){cin>>s[i];}
	int sum = 0;
	int a,b,c;
	a = min(s[0],s[2]);
	b = s[1];
	c = max(s[0],s[2]);
	sum += (b+a)*(c-a) + a*(2*b+a);
	a = min(s[3],s[5]);
	b = s[4];
	c = max(s[3],s[5]);
	sum += (b+a)*(c-a) + a*(2*b+a);
	cout<<sum<<endl;
}