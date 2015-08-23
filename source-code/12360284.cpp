//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
set<int> s;
int go[1000010];
set<int>::iterator it;
int main()
{
	int n,kk,a;
	cin>>n>>kk>>a;
	int now=(n+1)/(a+1);
	s.insert(0);
	s.insert(n+1);
	go[0]=(n+1)/(a+1);
	int m,t1;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t1;
		it=s.lower_bound(t1);
		int k=*it;
		it--;
		int f=*it;
		now-=go[f];
		go[f]=(t1-f)/(a+1);
		go[t1]=(k-t1)/(a+1);
		now+=go[f]+go[t1];
		//cout<<now<<endl;
		if(now<kk)
		{
			cout<<i<<endl;
			return 0;
		}
		s.insert(t1);
	}
	cout<<-1<<endl;
}
