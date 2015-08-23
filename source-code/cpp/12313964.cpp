//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<cstdlib>
#include<map>
#include<list>
#include<bits/stdc++.h>
using namespace std;

//	GC

#define in(a) scanf("%d",&a)
#define inll(a) scanf("%lld",&a)
#define ins(a) scanf("%s",a)
#define out(a) printf("%d\n",a)
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define outll(a) printf("%lld\n",a)
#define vec vector<int>
#define mod 1000000007
#define sortt(a) sort(a.begin(),a.end()) 
#define sz size()
#define mem(a,b) memset(a,(b),sizeof(a))
#define mp make_pair 
#define ll long long 
#define pa pair<int,int >
#define vecp vector<pa>

bool check(string s1,string s2)
{
	int i;
	
	if(s1==s2)		return true;
	
	int l1=s1.length(),l2=s2.length();
	
	if(l1%2 || l2%2)		return false;
	
	string t1,t2;
	string t3,t4;
	
	t1=s1.substr(0,l1/2);		t2=s1.substr(l1/2);
	t3=s2.substr(0,l2/2);		t4=s2.substr(l2/2);
	

	if(check(t1,t4) && check(t2,t3))	return true;
	if(check(t1,t3) && check(t2,t4))	return true;
	
	
	return false;
}

int main()
{
	string s1,s2;
	
	cin>>s1>>s2;
	
	if(s1.length()!=s2.length())		{	cout<<"NO";	return 0;	}
	
	if(check(s1,s2))		cout<<"YES";
	else					cout<<"NO";
	
	return 0;
}