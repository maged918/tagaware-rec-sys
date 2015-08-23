//Language: GNU C++


#include <bits/stdc++.h>
#define ll long long
using namespace std;
string smallest(string s)
{
	int l =s.length();
	if(l&1) //odd
	return s;
	else
	{
		string x1=smallest(s.substr(0,l/2));
		string x2=smallest(s.substr(l/2,l/2));
		if(x1<x2)
		return x1+x2;
		return x2+x1;
	}
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	s1=smallest(s1);
	s2=smallest(s2);
	//~ cout<<s1<<" "<<s2<<endl;
	if(s1==s2)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
