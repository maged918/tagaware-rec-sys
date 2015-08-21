//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int a[100010]={0};

int id[100010]={0};
int Out[100010][2]={{0}};

bool cmp(int a1,int a2)
{return a[a1]<a[a2];}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+N+1,cmp);
	for(int i=1;i<=N;i++)
	{
		Out[id[i]][1]=max(a[id[i]]-a[id[1]],a[id[N]]-a[id[i]]);
		Out[id[i]][0]=2e9;
		if(i>1) Out[id[i]][0]=a[id[i]]-a[id[i-1]];
		if(i<N) Out[id[i]][0]=min(Out[id[i]][0],a[id[i+1]]-a[id[i]]);
	}
	for(int i=1;i<=N;i++)
		printf("%d %d\n",Out[i][0],Out[i][1]);
	return 0;
}
