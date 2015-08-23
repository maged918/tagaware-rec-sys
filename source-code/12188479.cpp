//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int imax = 1000000;
string gsort(string s){
    if(s.size()%2)return s;
    string s1=gsort(s.substr(0,s.size()/2));
    string s2=gsort(s.substr(s.size()/2,s.size()));
    if(s1<s2)return (s1+s2);
    else return (s2+s1);
}
int main(){
    string a,b;
	cin>>a>>b;
	if(gsort(a) == gsort(b))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
