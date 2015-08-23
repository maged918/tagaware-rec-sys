//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string word ,word2 ;

bool check(string a,string b)
{
	if(a==b)return 1;
	int len=a.size() ;
	if(len&1||len==0)
		return 0;
	len>>=1;
	string temp ,temp1 ,tmp ,tmp1 ;
	temp.assign(a,0,len) ,temp1.assign(a,len,len) ,tmp.assign(b,0,len) ,tmp1.assign(b,len,len);
	if(check(temp,tmp1)&&check(temp1,tmp)||check(temp,tmp)&&check(temp1,tmp1))
		return 1;
	return 0;
}

int main()
{
	cin>>word>>word2;
	if(check(word,word2))
		puts("YES");
	else puts("NO");
	return 0;
}