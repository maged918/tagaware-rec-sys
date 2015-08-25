//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int a[200010]={0};
int N,K;
map <int,long long> G1;
map <int,long long> G2;

int main()
{
	long long ans=0;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%K==0)
		{
			map <int,long long>::iterator it2=G2.find(a[i]/K),it1;
			if(it2!=G2.end())
				ans+=it2->second;
			it2=G2.find(a[i]);
			it1=G1.find(a[i]/K);
			if(it2!=G2.end() && it1!=G1.end())
				G2[a[i]]=it2->second+it1->second;
			else if(it2==G2.end() && it1!=G1.end())
				G2[a[i]]=it1->second;
			it2=G2.find(a[i]/K),it1=G1.find(a[i]);
		}
		map<int,long long>::iterator it=G1.find(a[i]);
		if(it!=G1.end())
			G1[a[i]]=it->second+1;
		else G1[a[i]]=1;
	}
	cout<<ans<<endl;
	return 0;
}
